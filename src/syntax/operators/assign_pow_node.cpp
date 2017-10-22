#include <operators/assign_pow_node.hpp>

using namespace jawe;

assign_pow_node::assign_pow_node(const shared_node& left, const shared_node& right)
	: abstract_assign_node(left, right, "**=")
{}
