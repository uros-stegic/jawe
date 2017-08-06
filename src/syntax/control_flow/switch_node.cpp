#include <control_flow/switch_node.hpp>
#include <algorithm>

using namespace jawe;

switch_node::switch_node(const shared_node& expr, const std::vector<shared_node>& cases)
	: basic_node("switch")
	, m_expr(expr)
	, m_cases(cases)
{}

std::vector<shared_node>& switch_node::get_cases()
{
	return m_cases;
}

shared_node switch_node::get_expr()
{
	return m_expr;
}
