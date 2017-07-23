#include <operators/binary_operator_node.hpp>

using namespace jawe;

binary_operator_node::binary_operator_node(const shared_node& left, const shared_node& right, std::string symbol)
	: operator_node(symbol)
	, m_left(left)
	, m_right(right)
{}

shared_node binary_operator_node::get_right() const
{
	return m_right;
}

shared_node binary_operator_node::get_left() const
{
	return m_left;
}

