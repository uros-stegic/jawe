#include <operators/bit_xor_node.hpp>

using namespace jawe;

bit_xor_node::bit_xor_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "^")
{}

