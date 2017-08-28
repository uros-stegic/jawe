#include <operations/code_generator.hpp>
#include <utils/control.hpp>

using namespace jawe;

extern shared_node* program;

code_generator::code_generator()
	: m_llvm_builder(control::get().get_context())
{}
code_generator::code_generator(const code_generator& other)
	: m_llvm_builder(m_llvm_builder)
{}

void code_generator::run()
{
	codegen(*program);
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
			std::for_each(
				std::begin(nodes),
				std::end(nodes),
				[this](auto expr) {
					codegen(expr);
				}
			);
			return nullptr;
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
		}
	}, *root);
}

