#include <operators/logic_not_node.hpp>

using namespace jawe;

logic_not_node::logic_not_node(const shared_node& operand)
	: unary_operator_node(operand, "!")
{}

