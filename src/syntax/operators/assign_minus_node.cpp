#include <operators/assign_minus_node.hpp>

using namespace jawe;

assign_minus_node::assign_minus_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "-=")
{}

