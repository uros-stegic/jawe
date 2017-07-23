#include <operators/divide_node.hpp>

using namespace jawe;

divide_node::divide_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "/")
{}

