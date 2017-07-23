#include <operators/delete_node.hpp>

using namespace jawe;

delete_node::delete_node(const shared_node& operand)
	: unary_operator_node(operand, "delete")
{}

