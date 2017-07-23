#include <operators/bit_not_node.hpp>

using namespace jawe;

bit_not_node::bit_not_node(const shared_node& operand)
	: unary_operator_node(operand, "~")
{}

