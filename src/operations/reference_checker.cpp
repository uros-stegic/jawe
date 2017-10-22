#include <sstream>

#include <operations/reference_checker.hpp>
#include <utils/error_reporter.hpp>

using namespace jawe;

extern shared_node* program;

void reference_checker::run()
{
		check(*program);
}

void reference_checker::check(const shared_node& root)
{
		std::visit(lambda_composer {
			[](basic_node* node) {},
			[this](case_node* node) {
				check(node->get_case());
				check(node->get_body());
			},
			[this](command_block_node* node) {
				auto nodes = node->get_commands();
				// adding new scope to stack
				m_scopes.open_scope();
				// recursive call for every command
				// with new scopes stack
				std::for_each(
					std::begin(nodes),
					std::end(nodes),
					[this](auto expr) {
						check(expr);
					}
				);
				// remove last scope
				m_scopes.close_scope();
			},
			[this](default_node* node) {
				check(node->get_body());
			},
			[this](do_while_node* node) {
				check(node->get_body());
				check(node->get_expr());
			},
			[this](for_node* node) {
				// adding new scope to stack
				m_scopes.open_scope();
				check(node->get_init());
				check(node->get_expr());
				check(node->get_post());
				check(node->get_body());
				// remove last scope
				m_scopes.close_scope();
			},
			[this](if_else_node* node) {
			check(node->get_expr());
				// check for if body
				check(node->get_if());
				// check for else body if exists
				auto else_node = node->get_else();
				if(else_node != nullptr) {
					check(else_node);
				}
			},
			[this](return_node* node) {
				check(node->get_expr());
			},
			[this](switch_node* node) {
				check(node->get_expr());
				// check for every case
				auto nodes = node->get_cases();
				std::for_each(
					std::begin(nodes),
					std::end(nodes),
					[this](auto n) { check(n); }
				);
			},
			[this](while_node* node) {
				check(node->get_expr());
				check(node->get_body());
			},
			[this](array_node* node) {
				// check for every array arg
				auto nodes = node->get_elements();
				std::for_each(
					std::begin(nodes),
					std::end(nodes),
					[this](auto n) { check(n); }
				);
			},
			[this](object_node* node) {
				auto pairs = node->get_pairs();
				for(auto &p: pairs) {
					check(p.second);
				}
			},
			[this](binary_operator_node* node) {
				check(node->get_left());
				check(node->get_right());
			},
			[this](dot_access_node* node) {
				check(node->get_left());
			},
			[this](ternary_operator_node* node) {
				check(node->get_first_operand());
				check(node->get_second_operand());
				check(node->get_third_operand());
			},
			[this](unary_operator_node* node) {
				check(node->get_operand());
			},
			[this](function_call_node* node) {
				check(node->get_expr());
				// get function args
				auto args = node->get_args();
				// check for every arg
				if(args.size() != 0) {
					std::for_each(
						std::begin(args),
						std::end(args),
						[this](auto expr) {
							check(expr);
						}
					);
				}
				check(node->get_expr());
			},
			[this](function_declaration_node* node) {
				// add function name to scope
				m_scopes.insert(node->get_name());
				// check for function body
				check(node->get_function_object());
			},
			[this](function_object_node* node) {
				auto args = node->get_args();
				m_scopes.open_scope();
				// adding f.args to new scope stack
				std::for_each(
					std::begin(args),
					std::end(args),
					[this](auto arg) {
						m_scopes.insert(arg);
					}
				);
				check(node->get_body());
				m_scopes.close_scope();
			},
			[this, root](declaration_node* node) {
				// get variable name
				auto var_name = get_decl_var_name(node->get_expr());
				// check if var name already exists in last scope
				if(m_scopes.fetch_last(var_name)) {
					std::stringstream s;
					s << "Indentifier " << var_name << " has already been declared";
					error_reporter::error(s.str(), root);
				}
				// add var name to scope
				m_scopes.insert(var_name);
				// check for expr
				check(node->get_expr());
			},
			[this, root](variable_node* node) {
				if(!m_scopes.fetch(node->get_symbol())){
					// error
					std::stringstream s;
					s << "ReferenceError: " << node->get_symbol() << " is not defined";
					error_reporter::error(s.str(), root);
				}
			},
		}, *root);
}

std::string reference_checker::get_decl_var_name(const shared_node& root)
{
		return std::visit( lambda_composer {
			[this, root](variable_node* node) -> std::string {
				return node->get_name();
			},
			[this](abstract_assign_node* node) -> std::string {
				return get_decl_var_name(node->get_left());
			},
			[](basic_node* node) -> std::string {
				return "";
			}
		}, *root);
}
