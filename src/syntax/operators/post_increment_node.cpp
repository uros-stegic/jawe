#include <operators/post_increment_node.hpp>

using namespace jawe;

post_increment_node::post_increment_node(const shared_node& operand)
	: unary_operator_node(operand, "++")
{}

