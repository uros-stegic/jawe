#include <operators/typeof_node.hpp>

using namespace jawe;

typeof_node::typeof_node(const shared_node& operand)
	: unary_operator_node(operand, "typeof")
{}

