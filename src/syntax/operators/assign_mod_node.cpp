#include <operators/assign_mod_node.hpp>

using namespace jawe;

assign_mod_node::assign_mod_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "%=")
{}

