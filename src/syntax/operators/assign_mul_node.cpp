#include <operators/assign_mul_node.hpp>

using namespace jawe;

assign_mul_node::assign_mul_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "*=")
{}

