#include <operators/abstract_assign_node.hpp>

using namespace jawe;

abstract_assign_node::abstract_assign_node(const shared_node& left, const shared_node& right, std::string symbol)
	: binary_operator_node(left, right, symbol)
{}
