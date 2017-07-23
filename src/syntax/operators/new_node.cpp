#include <operators/new_node.hpp>

using namespace jawe;

new_node::new_node(const shared_node& operand)
	: unary_operator_node(operand, "new")
{}

