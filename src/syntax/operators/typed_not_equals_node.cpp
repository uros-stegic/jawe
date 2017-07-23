#include <operators/typed_not_equals_node.hpp>

using namespace jawe;

typed_not_equals_node::typed_not_equals_node(const shared_node& left, const shared_node& right)
	: binary_operator_node(left, right, "!==")
{}

