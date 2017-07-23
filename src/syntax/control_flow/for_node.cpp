#include <control_flow/for_node.hpp>

using namespace jawe;

for_node::for_node(const shared_node &init, const shared_node& cond, const shared_node& post, const shared_node& body)
	: basic_node("for")
	, m_init(init)
	, m_cond(cond)
	, m_post(post)
	, m_body(body)
{}

shared_node for_node::get_expr() const
{
	return m_cond;
}

shared_node for_node::get_body() const
{
	return m_body;
}

shared_node for_node::get_init() const
{
	return m_init;
}

shared_node for_node::get_post() const
{
	return m_post;
}

