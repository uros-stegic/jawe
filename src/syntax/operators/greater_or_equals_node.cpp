#include <operators/greater_or_equals_node.hpp>

using namespace jawe;

greater_or_equals_node::greater_or_equals_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, ">=")
{}

