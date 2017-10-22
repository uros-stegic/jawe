#include <operators/assign_div_node.hpp>

using namespace jawe;

assign_div_node::assign_div_node(const shared_node& left, const shared_node& right)
	: abstract_assign_node(left, right, "/=")
{}
