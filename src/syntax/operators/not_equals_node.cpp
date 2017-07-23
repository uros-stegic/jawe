#include <operators/not_equals_node.hpp>

using namespace jawe;

not_equals_node::not_equals_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "!=")
{}

