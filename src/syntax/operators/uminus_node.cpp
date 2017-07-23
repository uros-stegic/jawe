#include <operators/uminus_node.hpp>

using namespace jawe;

uminus_node::uminus_node(const shared_node& operand)
	: unary_operator_node(operand, "-")
{}

