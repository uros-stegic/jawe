#include <operators/ternary_conditional_node.hpp>

using namespace jawe;

ternary_conditional_node::ternary_conditional_node(const shared_node& first, const shared_node& second, const shared_node& third)
	: ternary_operator_node(first, second, third, "?", ":")
{}

