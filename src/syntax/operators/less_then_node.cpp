#include <operators/less_then_node.hpp>

using namespace jawe;

less_then_node::less_then_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "<")
{}

