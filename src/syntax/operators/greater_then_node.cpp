#include <operators/greater_then_node.hpp>

using namespace jawe;

greater_then_node::greater_then_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, ">")
{}

