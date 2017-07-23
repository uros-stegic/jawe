#include <control_flow/do_while_node.hpp>

using namespace jawe;

do_while_node::do_while_node(const shared_node& body, const shared_node& cond)
	: basic_node("do_while")
	, m_body(body)
	, m_cond(cond)
{}

shared_node do_while_node::get_expr() const
{
	return m_cond;
}

shared_node do_while_node::get_body() const
{
	return m_body;
}

