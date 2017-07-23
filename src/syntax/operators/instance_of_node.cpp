#include <operators/instance_of_node.hpp>

using namespace jawe;

instance_of_node::instance_of_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "instance_of")
{}

