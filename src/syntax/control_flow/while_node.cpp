#include <control_flow/while_node.hpp>

using namespace jawe;

while_node::while_node(const shared_node& cond, const shared_node& body)
	: basic_node("while")
	, m_expr(cond)
	, m_body(body)
{}

shared_node while_node::get_expr() const
{
	return m_expr;
}

shared_node while_node::get_body() const
{
	return m_body;
}
