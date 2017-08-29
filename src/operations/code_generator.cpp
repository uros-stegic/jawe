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
  
	llvm::Function* global_scope = llvm::Function::Create(FT, llvm::Function::ExternalLinkage, "global", control::get().get_module().get());
  
	llvm::BasicBlock *BB = llvm::BasicBlock::Create(control::get().get_context(), "entry", global_scope);
	m_ir_builder.SetInsertPoint(BB);
	
	auto expr = codegen(*program);
	if( expr != nullptr ) {
		m_ir_builder.CreateRet(expr);
	}
	else {
		global_scope->eraseFromParent();
	}
}

llvm::Value* code_generator::codegen(const shared_node& root)
{
	return std::visit(lambda_composer {
		[](basic_node* node) -> llvm::Value* {},
		[this](case_node* node) -> llvm::Value* {
			codegen(node->get_case());
			codegen(node->get_body());
			return nullptr;
		},
		[this](command_block_node* node) -> llvm::Value* {
			auto nodes = node->get_commands();
			llvm::Value* last = nullptr;
			std::for_each(
				std::begin(nodes),
				std::end(nodes),
				[this, &last](auto expr) {
					auto tmp = codegen(expr);
					if( tmp != nullptr ) {
						last = tmp;
					}
				}
			);
			return last;
		},
		[this](default_node* node) -> llvm::Value* {
			codegen(node->get_body());
			return nullptr;
		},
		[this](do_while_node* node) -> llvm::Value* {
			codegen(node->get_body());
			return nullptr;
		},
		[this](for_node* node) -> llvm::Value* {
			codegen(node->get_init());
			codegen(node->get_expr());
			codegen(node->get_post());
			codegen(node->get_body());
			return nullptr;
		},
		[this](if_else_node* node) -> llvm::Value* {
			codegen(node->get_if());
			auto else_node = node->get_else();
			if(else_node != nullptr) {
				codegen(else_node);
			}
			return nullptr;
		},
		[this](return_node* node) -> llvm::Value* {
			codegen(node->get_expr());
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
		[this](while_node* node) -> llvm::Value* {
			codegen(node->get_body());
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
		[this](function_call_node* node) -> llvm::Value* {
			auto args = node->get_args();
			std::for_each(
				std::begin(args),
				std::end(args),
				[this](auto expr) {
					codegen(expr);
				}
			);
			codegen(node->get_expr());
			return nullptr;
		},
		[this](function_declaration_node* node) -> llvm::Value* {
			codegen(node->get_function_object());
			return nullptr;
		},
		[this](function_object_node* node) -> llvm::Value* {
			codegen(node->get_body());
			return nullptr;
		},
		[this](declaration_node* node) -> llvm::Value* {
			codegen(node->get_expr());
			return nullptr;
		},
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
		[this](numeric_node* node) -> llvm::Value* {
			return llvm::ConstantFP::get(control::get().get_context(), llvm::APFloat(node->get_value()));
		}
	}, *root);
}

