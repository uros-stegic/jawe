#include <operators/void_node.hpp>

using namespace jawe;

void_node::void_node(const shared_node& operand)
	: unary_operator_node(operand, "void")
{}

