#include <operators/unary_operator_node.hpp>

using namespace jawe;

unary_operator_node::unary_operator_node(const shared_node& operand, std::string symbol)
	: operator_node(symbol)
	, m_operand(operand)
{}

shared_node unary_operator_node::get_operand() const
{
	return m_operand;
}

