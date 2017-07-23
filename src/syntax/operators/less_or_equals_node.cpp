#include <operators/less_or_equals_node.hpp>

using namespace jawe;

less_or_equals_node::less_or_equals_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "<=")
{}

