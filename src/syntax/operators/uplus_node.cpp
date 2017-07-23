#include <operators/uplus_node.hpp>

using namespace jawe;

uplus_node::uplus_node(const shared_node& operand)
	: unary_operator_node(operand, "+")
{}

