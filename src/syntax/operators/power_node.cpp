#include <operators/power_node.hpp>

using namespace jawe;

power_node::power_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "**")
{}

