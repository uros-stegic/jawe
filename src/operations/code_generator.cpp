#include <operations/code_generator.hpp>

#include <utils/control.hpp>

using namespace jawe;

extern shared_node* program;

code_generator::code_generator()
	: m_ir_builder(control::get().get_context())
{}

void code_generator::run()
{
	std::vector<llvm::Type*> empty_func_type(0, llvm::Type::getDoubleTy(control::get().get_context()));
	llvm::FunctionType *FT = llvm::FunctionType::get(llvm::Type::getDoubleTy(control::get().get_context()), empty_func_type, false);

	llvm::Function* main_fn= llvm::Function::Create(FT, llvm::Function::ExternalLinkage, "global", control::get().get_module().get());

	llvm::BasicBlock *BB = llvm::BasicBlock::Create(control::get().get_context(), "entry", main_fn);
	m_ir_builder.SetInsertPoint(BB);

	auto zero = llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0));
	auto expr = codegen(*program);
	if( expr != nullptr ) {
		m_ir_builder.SetInsertPoint(BB);
		m_ir_builder.CreateRet(zero);
	}
	else {
		main_fn->eraseFromParent();
	}
}

llvm::Value* code_generator::codegen(const shared_node& root)
{
	return std::visit(lambda_composer {
		[](basic_node* node) -> llvm::Value* { return nullptr; },
		[this](case_node* node) -> llvm::Value* {
			codegen(node->get_case());
			codegen(node->get_body());
			return nullptr;
		},
		[this](command_block_node* node) -> llvm::Value* {
			auto nodes = node->get_commands();
			llvm::Value* last = nullptr;
			auto current_bb = m_ir_builder.GetInsertBlock();
			m_scopes.open_scope();
			std::for_each(
				std::begin(nodes),
				std::end(nodes),
				[this, &last, current_bb](auto expr) {
					auto tmp = codegen(expr);
					if( tmp != nullptr ) {
						m_ir_builder.SetInsertPoint(current_bb);
						last = tmp;
					}
				}
			);
			m_scopes.close_scope();
			return last;
		},
		[this](default_node* node) -> llvm::Value* {
			codegen(node->get_body());
			return nullptr;
		},
		[this](switch_node* node) -> llvm::Value* {
			auto nodes = node->get_cases();
			std::for_each(
				std::begin(nodes),
				std::end(nodes),
				[this](auto n) { codegen(n); }
			);
			return nullptr;
		},
		[this](array_node* node) -> llvm::Value* {
			auto nodes = node->get_elements();
			std::for_each(
				std::begin(nodes),
				std::end(nodes),
				[this](auto n) { codegen(n); }
			);
			return nullptr;
		},
		[this](object_node* node) -> llvm::Value* {
			auto pairs = node->get_pairs();
			for(auto &p: pairs) {
				codegen(p.second);
			}
			return nullptr;
		},
		[this](binary_operator_node* node) -> llvm::Value* {
			codegen(node->get_left());
			codegen(node->get_right());
			return nullptr;
		},
		[this](ternary_operator_node* node) -> llvm::Value* {
			codegen(node->get_first_operand());
			codegen(node->get_second_operand());
			codegen(node->get_third_operand());
			return nullptr;
		},
		[this](unary_operator_node* node) -> llvm::Value* {
			codegen(node->get_operand());
			return nullptr;
		},

		/**************** Variable nodes *****************/
		[this](declaration_node* node) -> llvm::Value* {
			auto expr = node->get_expr();
			return std::visit(lambda_composer{
				[](basic_node* node) -> llvm::Value* { return nullptr; },
				[this](variable_node* node) -> llvm::Value* {
					auto var_name = node->get_name();
					auto alloca = create_alloca(m_ir_builder.GetInsertBlock()->getParent(), var_name.c_str());
					m_scopes.insert(var_name, alloca);
					return alloca;
				},
				[this, expr](assign_node* node) -> llvm::Value* {
					return codegen(expr);
				}
			}, *expr);
			return codegen(node->get_expr());
		},
		[this](variable_node* node) -> llvm::Value* {
			auto var = m_scopes.fetch(node->get_name());
			return m_ir_builder.CreateLoad(*var, node->get_name().c_str());
		},
		[this](assign_node* node) -> llvm::Value* {
			auto right = codegen(node->get_right());
			auto var_name = std::get<variable_node*>(*(node->get_left()))->get_name();

			// Allocating space in stack for variable
			auto alloca = m_scopes.fetch(var_name);
			if( *alloca == nullptr ) {
				*alloca = create_alloca(m_ir_builder.GetInsertBlock()->getParent(), var_name.c_str());
			}

			// Storing a value in pre-allocated space
			m_ir_builder.CreateStore(right, *alloca);

			// Stacking ptr to stacked variable
			m_scopes.insert(var_name, *alloca);
			return right;
		},
		/*************************************************/

		/*************** Arithmetic nodes ****************/
		[this](plus_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			return m_ir_builder.CreateFAdd(left, right, "addtmp");
		},
		[this](minus_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			return m_ir_builder.CreateFSub(left, right, "subtmp");
		},
		[this](times_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			return m_ir_builder.CreateFMul(left, right, "multmp");
		},
		[this](divide_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			return m_ir_builder.CreateFDiv(left, right, "divtmp");
		},
		[this](mod_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			return m_ir_builder.CreateFRem(left, right, "fremtmp");
		},
		[this](uminus_node* node) -> llvm::Value* {
			auto op = codegen(node->get_operand());
			auto zero = llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0));

			return m_ir_builder.CreateFSub(zero, op, "subtmp");
		},
		[this](uplus_node* node) -> llvm::Value* {
			auto op = codegen(node->get_operand());
			auto zero = llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0));

			return m_ir_builder.CreateFAdd(zero, op, "addtmp");
		},
		/*************************************************/

		/****************** Bitwise ops ******************/
		[this](bit_and_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			return m_ir_builder.CreateAnd(left, right, "andtmp");
		},
		[this](bit_or_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			return m_ir_builder.CreateOr(left, right, "ortmp");
		},
		[this](bit_xor_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			return m_ir_builder.CreateXor(left, right, "xortmp");
		},
		[this](bit_not_node* node) -> llvm::Value* {
			auto op = codegen(node->get_operand());

			return m_ir_builder.CreateNot(op, "nottmp");
		},
		/*************************************************/

		/****************** Logical ops ******************/
		[this](logic_and_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			/* tmp = x & y */
			auto andtmp = m_ir_builder.CreateAnd(left, right, "andtmp");
			auto zero = llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0));

			/* result = (x & y) != 0 */
			auto slttmp = m_ir_builder.CreateFCmpONE(andtmp, zero, "gletmp");
			return m_ir_builder.CreateUIToFP(slttmp, llvm::Type::getDoubleTy(control::get().get_context()));
		},
		[this](logic_or_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			/* tmp = x | y */
			auto andtmp = m_ir_builder.CreateOr(left, right, "ortmp");
			auto zero = llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0));

			/* result = (x | y) != 0 */
			auto slttmp = m_ir_builder.CreateFCmpONE(andtmp, zero, "gletmp");
			return m_ir_builder.CreateUIToFP(slttmp, llvm::Type::getDoubleTy(control::get().get_context()));
		},
		[this](logic_not_node* node) -> llvm::Value* {
			auto op = codegen(node->get_operand());

			auto zero = llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0));

			/* tmp = x == 0 */
			auto slttmp = m_ir_builder.CreateFCmpOEQ(op, zero, "slttmp");
			return m_ir_builder.CreateUIToFP(slttmp, llvm::Type::getDoubleTy(control::get().get_context()));
		},
		/*************************************************/

		/****************** Shift nodes ******************/
		[this](bit_shift_l_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			return m_ir_builder.CreateShl(left, right, "shltmp");
		},
		[this](bit_shift_r_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			return m_ir_builder.CreateAShr(left, right, "ashrtmp");
		},
		[this](bit_shift_u_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			return m_ir_builder.CreateLShr(left, right, "lshrtmp");
		},
		/*************************************************/

		/***************** Compare nodes *****************/
		[this](less_then_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			auto slttmp = m_ir_builder.CreateFCmpULT(left, right, "ulttmp");
			return m_ir_builder.CreateUIToFP(slttmp, llvm::Type::getDoubleTy(control::get().get_context()));
		},
		[this](greater_then_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			auto slttmp = m_ir_builder.CreateFCmpUGT(left, right, "ulttmp");
			return m_ir_builder.CreateUIToFP(slttmp, llvm::Type::getDoubleTy(control::get().get_context()));
		},
		[this](less_or_equals_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			auto slttmp = m_ir_builder.CreateFCmpULE(left, right, "uletmp");
			return m_ir_builder.CreateUIToFP(slttmp, llvm::Type::getDoubleTy(control::get().get_context()));
		},
		[this](greater_or_equals_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			auto slttmp = m_ir_builder.CreateFCmpUGE(left, right, "gletmp");
			return m_ir_builder.CreateUIToFP(slttmp, llvm::Type::getDoubleTy(control::get().get_context()));
		},
		[this](equals_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			auto slttmp = m_ir_builder.CreateFCmpOEQ(left, right, "gletmp");
			return m_ir_builder.CreateUIToFP(slttmp, llvm::Type::getDoubleTy(control::get().get_context()));
		},
		[this](not_equals_node* node) -> llvm::Value* {
			auto left = codegen(node->get_left());
			auto right = codegen(node->get_right());

			auto slttmp = m_ir_builder.CreateFCmpONE(left, right, "gletmp");
			return m_ir_builder.CreateUIToFP(slttmp, llvm::Type::getDoubleTy(control::get().get_context()));
		},
		/*************************************************/

		/***************** Numeric nodes *****************/
		[this](numeric_node* node) -> llvm::Value* {
			return llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(node->get_value()));
		},
		/*************************************************/

		/***************** Control nodes *****************/
		[this](if_else_node* node) -> llvm::Value* {
			auto cond = m_ir_builder.CreateFCmpONE(codegen(node->get_expr()), llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0)), "ifcond");
			auto current_function = m_ir_builder.GetInsertBlock()->getParent();

			// enable branching points
			auto then_bb = llvm::BasicBlock::Create(control::get().get_context(), "then", current_function);
			auto else_bb = llvm::BasicBlock::Create(control::get().get_context(), "else");
			auto merge_bb = llvm::BasicBlock::Create(control::get().get_context(), "ifcont");

			m_ir_builder.CreateCondBr(cond, then_bb, else_bb);

			// if-branch
			m_ir_builder.SetInsertPoint(then_bb);
			auto then_ir = codegen(node->get_if());
			m_ir_builder.CreateBr(merge_bb);
			then_bb = m_ir_builder.GetInsertBlock();

			// else-branch
			auto else_node = node->get_else();
			llvm::Value* else_ir;
			if( else_node ) {
				current_function->getBasicBlockList().push_back(else_bb);
				m_ir_builder.SetInsertPoint(else_bb);
				else_ir = codegen(else_node);
				m_ir_builder.CreateBr(merge_bb);
				else_bb = m_ir_builder.GetInsertBlock();
			}

			// merging branches
			current_function->getBasicBlockList().push_back(merge_bb);
			m_ir_builder.SetInsertPoint(merge_bb);
			auto phi_node = m_ir_builder.CreatePHI(llvm::Type::getDoubleTy(control::get().get_context()), 2, "iftmp");
			phi_node->addIncoming(then_ir, then_bb);
			if( else_node ) {
				phi_node->addIncoming(else_ir, then_bb);
			}

			return phi_node;
		},
		[this](for_node* node) -> llvm::Value* {
			m_scopes.open_scope();
				auto init_val = codegen(node->get_init());
				auto current_function = m_ir_builder.GetInsertBlock()->getParent();

				/* basic block for initialization part*/
				auto entry_bb = m_ir_builder.GetInsertBlock();

				/* basic block for condition checking */
				auto cond_bb = llvm::BasicBlock::Create(control::get().get_context(), "cond", current_function);

				/* basic block for real loop to happen */
				auto loop_bb = llvm::BasicBlock::Create(control::get().get_context(), "loop", current_function);

				/* basic block for after loop */
				auto after_loop_bb = llvm::BasicBlock::Create(control::get().get_context(), "afterloop", current_function);

				m_ir_builder.SetInsertPoint(entry_bb);
				m_ir_builder.CreateBr(cond_bb); /* goto: condition check */

				/* Starting the outer loop (condition check) */
				m_ir_builder.SetInsertPoint(cond_bb);

				auto phi_node = m_ir_builder.CreatePHI(llvm::Type::getDoubleTy(control::get().get_context()), 2, "loop_phi_node");
				phi_node->addIncoming(init_val, entry_bb);
				phi_node->addIncoming(init_val, loop_bb);

				/* cond = i < n */
				auto cond = codegen(node->get_expr());

				/* cond = i < n == 0 */
				cond = m_ir_builder.CreateFCmpONE(cond, llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0)), "loopcond");

				/* if cond == 0 goto after loop, owherwise goto inner loop */
				m_ir_builder.CreateCondBr(cond, loop_bb, after_loop_bb);

				m_ir_builder.SetInsertPoint(loop_bb);
				m_scopes.open_scope();
					/* Inner loop (real loop body) */
					auto body = codegen(node->get_body());
					auto post = codegen(node->get_post());
				m_scopes.close_scope();

				/* goto: condition check */
				m_ir_builder.CreateBr(cond_bb);

  				m_ir_builder.SetInsertPoint(after_loop_bb);
			m_scopes.close_scope();
			return llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0));
		},
		[this](do_while_node* node) -> llvm::Value* {
			auto zero = llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0));
			m_scopes.open_scope();
				auto current_function = m_ir_builder.GetInsertBlock()->getParent();

				/* basic block for initialization part*/
				auto entry_bb = m_ir_builder.GetInsertBlock();

				/* basic block for real loop to happen */
				auto loop_bb = llvm::BasicBlock::Create(control::get().get_context(), "loop", current_function);

				/* basic block for after loop */
				auto after_loop_bb = llvm::BasicBlock::Create(control::get().get_context(), "afterloop", current_function);

				m_ir_builder.SetInsertPoint(entry_bb);
				m_ir_builder.CreateBr(loop_bb); /* goto: inner loop */

				/* Starting the inner loop */
				m_ir_builder.SetInsertPoint(loop_bb);

				auto phi_node = m_ir_builder.CreatePHI(llvm::Type::getDoubleTy(control::get().get_context()), 2, "loop_phi_node");
				phi_node->addIncoming(zero, entry_bb);
				phi_node->addIncoming(zero, loop_bb);

				m_ir_builder.SetInsertPoint(loop_bb);
				m_scopes.open_scope();
					auto body = codegen(node->get_body());
				m_scopes.close_scope();

				/* cond = i < n */
				auto cond = codegen(node->get_expr());

				/* cond = i < n == 0 */
				cond = m_ir_builder.CreateFCmpONE(cond, llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0)), "loopcond");

				/* if cond == 0 goto after loop, owherwise goto inner loop */
				m_ir_builder.CreateCondBr(cond, loop_bb, after_loop_bb);

  				m_ir_builder.SetInsertPoint(after_loop_bb);
			m_scopes.close_scope();
			return zero;
		},
		[this](while_node* node) -> llvm::Value* {
			auto zero = llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0));
			m_scopes.open_scope();
				auto current_function = m_ir_builder.GetInsertBlock()->getParent();

				/* basic block for initialization part*/
				auto entry_bb = m_ir_builder.GetInsertBlock();

				/* basic block for condition checking */
				auto cond_bb = llvm::BasicBlock::Create(control::get().get_context(), "cond", current_function);

				/* basic block for real loop to happen */
				auto loop_bb = llvm::BasicBlock::Create(control::get().get_context(), "loop", current_function);

				/* basic block for after loop */
				auto after_loop_bb = llvm::BasicBlock::Create(control::get().get_context(), "afterloop", current_function);

				m_ir_builder.SetInsertPoint(entry_bb);
				m_ir_builder.CreateBr(cond_bb); /* goto: condition check */

				/* Starting the outer loop (condition check) */
				m_ir_builder.SetInsertPoint(cond_bb);

				auto phi_node = m_ir_builder.CreatePHI(llvm::Type::getDoubleTy(control::get().get_context()), 2, "loop_phi_node");
				phi_node->addIncoming(zero, entry_bb);
				phi_node->addIncoming(zero, loop_bb);

				/* cond = i < n */
				auto cond = codegen(node->get_expr());

				/* cond = i < n == 0 */
				cond = m_ir_builder.CreateFCmpONE(cond, llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(0.0)), "loopcond");

				/* if cond == 0 goto after loop, owherwise goto inner loop */
				m_ir_builder.CreateCondBr(cond, loop_bb, after_loop_bb);

				m_ir_builder.SetInsertPoint(loop_bb);
				m_scopes.open_scope();
					/* Inner loop (real loop body) */
					auto body = codegen(node->get_body());
				m_scopes.close_scope();

				/* goto: condition check */
				m_ir_builder.CreateBr(cond_bb);

  				m_ir_builder.SetInsertPoint(after_loop_bb);
			m_scopes.close_scope();
			return zero;
		},
		/*************************************************/

		/**************** Function nodes *****************/
		[this](function_declaration_node* node) -> llvm::Value* {
			auto fn_name = node->get_name();

			auto fn_object = std::get<function_object_node*>(*(node->get_function_object()));
			auto args = fn_object->get_args();
			std::vector<llvm::Type*> arg_types(args.size(), llvm::Type::getDoubleTy(control::get().get_context()));
			auto fn_type = llvm::FunctionType::get(llvm::Type::getDoubleTy(control::get().get_context()), arg_types, false); // R^n -> R

			auto fn = llvm::Function::Create(fn_type, llvm::Function::ExternalLinkage, fn_name, control::get().get_module().get());

			unsigned idx = 0;
			for( auto &arg : fn->args() ) {
				arg.setName(args[idx++]);
			}

			// Create a new basic block to start insertion into.
			auto fn_bb = llvm::BasicBlock::Create(control::get().get_context(), "entry", fn);
			m_ir_builder.SetInsertPoint(fn_bb);

			// Record the function arguments in the NamedValues map.
			m_scopes.open_scope();
			for (auto &arg : fn->args()) {
				auto arg_name = arg.getName().str();
				auto arg_alloca = create_alloca(fn, arg_name.c_str());
				m_scopes.insert(arg.getName().str(), arg_alloca);
				m_ir_builder.CreateStore(&arg, arg_alloca);
			}

			m_scopes.open_scope();
			auto ret_val = codegen(node->get_body());
			m_scopes.close_scope();
			m_ir_builder.CreateRet(ret_val);

			//fn_pass_mgr->run(*fn);

			m_scopes.close_scope();
			return fn;
		},
		[this](function_object_node* node) -> llvm::Value* {
			m_scopes.open_scope();
			codegen(node->get_body());
			m_scopes.close_scope();
			return nullptr;
		},
		[this](return_node* node) -> llvm::Value* {
			return codegen(node->get_expr());
		},
		[this](function_call_node* node) -> llvm::Value* {
			//TODO: extract fn name in all other cases
			//this is only for funtion foo() {} case.
			auto fn_name = std::visit(lambda_composer{
				[](basic_node* node) -> std::string { return ""; },
				[](variable_node* node) -> std::string { return node->get_name(); }
			}, *(node->get_expr()));

			llvm::Function *callee = control::get().get_module()->getFunction(fn_name);
			auto args = node->get_args();

			std::vector<llvm::Value *> callee_args;
			for(auto &&arg : args) {
				callee_args.push_back(codegen(arg));
			}

			return m_ir_builder.CreateCall(callee, callee_args, "calltmp");
		},
		/*************************************************/
	}, *root);
}


llvm::AllocaInst* code_generator::create_alloca(llvm::Function* f, const char* var_name) const
{
	llvm::IRBuilder<> entry_block_builder(
		&f->getEntryBlock(),
		f->getEntryBlock().begin()
	);
	return entry_block_builder.CreateAlloca(
		llvm::Type::getDoubleTy(control::get().get_context()),
		0,
		var_name
	);
}
