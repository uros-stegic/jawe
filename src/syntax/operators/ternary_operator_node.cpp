#include <operators/ternary_operator_node.hpp>

using namespace jawe;

ternary_operator_node::ternary_operator_node(
	const shared_node& first_operand,
	const shared_node& second_operand,
	const shared_node& third_operand,
	std::string symbol,
	std::string symbol2
)
	: operator_node(symbol)
	, m_first(first_operand)
	, m_second(second_operand)
	, m_third(third_operand)
	, m_symbol2(symbol2)
{}

shared_node ternary_operator_node::first_operand() const
{
	return m_first;
}

shared_node ternary_operator_node::second_operand() const
{
	return m_second;
}

shared_node ternary_operator_node::third_operand() const
{
	return m_third;
}

