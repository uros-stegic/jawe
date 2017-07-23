#include <control_flow/if_else_node.hpp>

using namespace jawe;

if_else_node::if_else_node(const shared_node& expr, const shared_node& if_command, const shared_node& else_command)
	: basic_node("if_else")
	, m_expr(expr)
	, m_if(if_command)
	, m_else(else_command)
{}

shared_node if_else_node::get_expr() const
{
	return m_expr;
}
shared_node if_else_node::get_if() const
{
	return m_if;
}
shared_node if_else_node::get_else() const
{
	return m_else;
}

