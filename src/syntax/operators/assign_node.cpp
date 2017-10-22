#include <operators/assign_node.hpp>

using namespace jawe;

assign_node::assign_node(const shared_node& left, const shared_node& right)
	: abstract_assign_node(left, right, "=")
{}
