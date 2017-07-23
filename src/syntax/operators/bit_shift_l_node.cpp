#include <operators/bit_shift_l_node.hpp>

using namespace jawe;

bit_shift_l_node::bit_shift_l_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "<<")
{}

