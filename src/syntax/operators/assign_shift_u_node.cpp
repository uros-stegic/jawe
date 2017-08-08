#include <operators/assign_shift_u_node.hpp>

using namespace jawe;

assign_shift_u_node::assign_shift_u_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, ">>>=")
{}
