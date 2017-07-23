#include <operators/array_access_node.hpp>

using namespace jawe;

array_access_node::array_access_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "[]")
{}
