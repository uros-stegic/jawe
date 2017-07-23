#include <operators/in_node.hpp>

using namespace jawe;

in_node::in_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "in")
{}

