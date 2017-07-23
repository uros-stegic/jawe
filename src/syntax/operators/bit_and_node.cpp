#include <operators/bit_and_node.hpp>

using namespace jawe;

bit_and_node::bit_and_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "&")
{}

