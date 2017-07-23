#include <operators/equals_node.hpp>

using namespace jawe;

equals_node::equals_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "==")
{}

