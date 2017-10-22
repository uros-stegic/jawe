#include <operators/assign_plus_node.hpp>

using namespace jawe;

assign_plus_node::assign_plus_node(const shared_node& left, const shared_node& right)
	: abstract_assign_node(left, right, "+=")
{}
