#include <operators/mod_node.hpp>

using namespace jawe;

mod_node::mod_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "%")
{}

