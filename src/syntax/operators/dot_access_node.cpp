#include <operators/dot_access_node.hpp>

using namespace jawe;

dot_access_node::dot_access_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, ".")
{}

