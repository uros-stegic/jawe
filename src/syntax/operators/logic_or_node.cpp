#include <operators/logic_or_node.hpp>

using namespace jawe;

logic_or_node::logic_or_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "||")
{}

