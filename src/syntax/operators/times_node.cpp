#include <operators/times_node.hpp>

using namespace jawe;

times_node::times_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "*")
{}

