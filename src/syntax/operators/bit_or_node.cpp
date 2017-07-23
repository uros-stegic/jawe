#include <operators/bit_or_node.hpp>

using namespace jawe;

bit_or_node::bit_or_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "|")
{}

