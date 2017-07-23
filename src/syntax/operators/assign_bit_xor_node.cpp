#include <operators/assign_bit_xor_node.hpp>

using namespace jawe;

assign_bit_xor_node::assign_bit_xor_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "^=")
{}

