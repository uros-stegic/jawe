#include <operators/minus_node.hpp>

using namespace jawe;

minus_node::minus_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "-")
{}

