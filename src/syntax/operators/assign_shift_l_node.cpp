#include <operators/assign_shift_l_node.hpp>

using namespace jawe;

assign_shift_l_node::assign_shift_l_node(const shared_node& left, const shared_node& right)
	: abstract_assign_node(left, right, "<<=")
{}
