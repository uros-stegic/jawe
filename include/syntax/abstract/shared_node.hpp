#ifndef __SHARED_NODE_HPP__
#define __SHARED_NODE_HPP__

#include <string>
#include <vector>
#include <variant>
#include <iostream>
#include <memory>
#include <utils/lambda_composer.hpp>


namespace jawe {

// Concrete classes
class let_declaration_node;
class const_declaration_node;
class var_declaration_node;
class variable_node;
class function_declaration_node;
class function_object_node;
class array_node;
class false_node;
class nan_node;
class numeric_node;
class object_node;
class string_node;
class true_node;
class undefined_node;
class null_node;
class break_node;
class case_node;
class continue_node;
class default_node;
class do_while_node;
class empty_node;
class command_block_node;
class for_node;
class if_else_node;
class return_node;
class switch_node;
class while_node;
class array_access_node;
class assign_bit_con_node;
class assign_bit_dis_node;
class assign_bit_xor_node;
class assign_div_node;
class assign_minus_node;
class assign_mod_node;
class assign_mul_node;
class assign_node;
class assign_plus_node;
class assign_pow_node;
class assign_shift_l_node;
class assign_shift_r_node;
class assign_shift_u_node;
class bit_and_node;
class bit_not_node;
class bit_or_node;
class bit_shift_l_node;
class bit_shift_r_node;
class bit_shift_u_node;
class bit_xor_node;
class decrement_node;
class delete_node;
class divide_node;
class dot_access_node;
class equals_node;
class function_call_node;
class greater_or_equals_node;
class greater_then_node;
class increment_node;
class in_node;
class instance_of_node;
class less_or_equals_node;
class less_then_node;
class logic_and_node;
class logic_not_node;
class logic_or_node;
class minus_node;
class mod_node;
class new_node;
class not_equals_node;
class plus_node;
class post_decrement_node;
class post_increment_node;
class power_node;
class ternary_conditional_node;
class times_node;
class typed_equals_node;
class typed_not_equals_node;
class typeof_node;
class uminus_node;
class uplus_node;
class void_node;

using node_variant = std::variant<let_declaration_node*,
									const_declaration_node*,
									var_declaration_node*,
									variable_node*,
									function_declaration_node*,
									function_object_node*,
									array_node*,
									false_node*,
									nan_node*,
									numeric_node*,
									object_node*,
									string_node*,
									true_node*,
									undefined_node*,
									null_node*,
									break_node*,
									case_node*,
									continue_node*,
									default_node*,
									do_while_node*,
									empty_node*,
									command_block_node*,
									for_node*,
									if_else_node*,
									return_node*,
									switch_node*,
									while_node*,
									array_access_node*,
									assign_bit_con_node*,
									assign_bit_dis_node*,
									assign_bit_xor_node*,
									assign_div_node*,
									assign_minus_node*,
									assign_mod_node*,
									assign_mul_node*,
									assign_node*,
									assign_plus_node*,
									assign_pow_node*,
									assign_shift_l_node*,
									assign_shift_r_node*,
									assign_shift_u_node*,
									bit_and_node*,
									bit_not_node*,
									bit_or_node*,
									bit_shift_l_node*,
									bit_shift_r_node*,
									bit_shift_u_node*,
									bit_xor_node*,
									decrement_node*,
									delete_node*,
									divide_node*,
									dot_access_node*,
									equals_node*,
									function_call_node*,
									greater_or_equals_node*,
									greater_then_node*,
									increment_node*,
									in_node*,
									instance_of_node*,
									less_or_equals_node*,
									less_then_node*,
									logic_and_node*,
									logic_not_node*,
									logic_or_node*,
									minus_node*,
									mod_node*,
									new_node*,
									not_equals_node*,
									plus_node*,
									post_decrement_node*,
									post_increment_node*,
									power_node*,
									ternary_conditional_node*,
									times_node*,
									typed_equals_node*,
									typed_not_equals_node*,
									typeof_node*,
									uminus_node*,
									uplus_node*,
									void_node*
								>;

struct deleter {
	void operator()(node_variant*);
};

using shared_node = std::shared_ptr<node_variant>;

template<class NodeT, typename... Args>
shared_node make_node(Args... args)
{
	return shared_node(new node_variant(new NodeT(args...)),
						   deleter());
}

template<class NodeT, typename... Args>
shared_node* make_node_ptr(Args... args)
{
	return new shared_node(new node_variant(new NodeT(args...)),
						   deleter());
}

class basic_node {
public:
	std::string get_symbol() const;

protected:
	basic_node(std::string);

private:
	std::string m_symbol;
};
}
#endif // __SHARED_NODE_HPP__
