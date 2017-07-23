#include <operators/logic_and_node.hpp>

using namespace jawe;

logic_and_node::logic_and_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "&&")
{}

