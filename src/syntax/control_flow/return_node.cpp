#include <control_flow/return_node.hpp>

using namespace jawe;

return_node::return_node(const shared_node& expr)
	: basic_node("return")
	, m_expr(expr)
{}

shared_node return_node::get_expr() const
{
	return m_expr;
}
