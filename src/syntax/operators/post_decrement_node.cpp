#include <operators/post_decrement_node.hpp>

using namespace jawe;

post_decrement_node::post_decrement_node(const shared_node& operand)
	: unary_operator_node(operand, "--")
{}

