#include <operations/reference_checker.hpp>
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
				auto new_scope = std::vector<std::string>();
				// adding new scope to stack
				m_scopes.push_back(new_scope);
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
				m_scopes.pop_back();
			},
			[this](default_node* node) {
				check(node->get_body());
			},
			[this](do_while_node* node) {
				check(node->get_body());
			},
			[this](for_node* node) {
				auto new_scope = std::vector<std::string>();
				// adding new scope to stack
				m_scopes.push_back(new_scope);
				check(node->get_init());
				check(node->get_expr());
				check(node->get_post());
				check(node->get_body());
				// remove last scope
				m_scopes.pop_back();
			},
			[this](if_else_node* node) {
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
				// check for every case
				auto nodes = node->get_cases();
				std::for_each(
					std::begin(nodes),
					std::end(nodes),
					[this](auto n) { check(n); }
				);
			},
			[this](while_node* node) {
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
				// get last scope
				auto last_scope = m_scopes.rbegin();
				// add function name to scope
				last_scope->push_back(node->get_name());
				// check for function body
				check(node->get_function_object());
			},
			[this](function_object_node* node) {
				auto new_scope = std::vector<std::string>();
				auto args = node->get_args();
				// adding f.args to new scope stack
				std::for_each(
					std::begin(args),
					std::end(args),
					[&new_scope](auto arg) {
						new_scope.push_back(arg);
					}
				);
				m_scopes.push_back(new_scope);
				check(node->get_body());
				m_scopes.pop_back();
			},
			[this](declaration_node* node) {
				// get last scope
				auto last_scope = m_scopes.rbegin();
				// get variable name
				auto var_name = get_decl_var_name(node->get_expr());
				// check if var name already exists in last scope
				if(std::find(last_scope->begin(), last_scope->end(), var_name) != last_scope->end()) {
					std::cerr << "Indentifier " << var_name << " has already been declared" << std::endl;
				}
				// add var name to scope
				last_scope->push_back(var_name);
				// check for expr
				check(node->get_expr());
			},
			[this](variable_node* node) {
				if(!find_variable(node->get_symbol())){
					// error
					std::cerr << "ReferenceError: " << node->get_symbol() << " is not defined" << std::endl;
				}
			},
		}, *root);
}

bool reference_checker::find_variable(const std::string& variable) const
{
	bool x = std::find_if(m_scopes.begin(), m_scopes.end(),
									 [variable](auto scope){
										 	return std::find(scope.begin(), scope.end(), variable) != scope.end();
										}) != m_scopes.end();
	return x;
}

void reference_checker::print_stacks() const
{
	std::cout << "================================" << '\n';
	for(int i = 0; i < m_scopes.size(); i++){
		std::cout << "	Stack No." << i << std::endl;
		for(int j=0; j<m_scopes[i].size(); j++)
			std::cout << "		Elem: " << m_scopes[i][j] << std::endl;
	}
	std::cout << "================================" << '\n';
}

std::string reference_checker::get_decl_var_name(const shared_node& root)
{
		return std::visit( lambda_composer {
			[this, root](variable_node* node) -> std::string {
				return node->get_name();
			},
			[this](assign_node* node) -> std::string {
				return get_decl_var_name(node->get_left());
			},
			[](basic_node* node) -> std::string {
				return "";
			}
		}, *root);
}
