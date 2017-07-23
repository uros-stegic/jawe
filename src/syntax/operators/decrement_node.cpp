#include <operators/decrement_node.hpp>

using namespace jawe;

decrement_node::decrement_node(const shared_node& operand)
	: unary_operator_node(operand, "--")
{}

