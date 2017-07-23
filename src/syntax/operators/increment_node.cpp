#include <operators/increment_node.hpp>

using namespace jawe;

increment_node::increment_node(const shared_node& operand)
	: unary_operator_node(operand, "++")
{}

