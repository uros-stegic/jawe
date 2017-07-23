#include <operators/plus_node.hpp>

using namespace jawe;

plus_node::plus_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "+")
{}

