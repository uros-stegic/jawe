#include <variables/declaration_node.hpp>

using namespace jawe;

declaration_node::declaration_node(const shared_node& node,qualifier qualif, std::string symbol)
	:basic_node(symbol)
	,m_expr(node)
	,m_qualifier(qualif)
{}

qualifier declaration_node::get_qualifier() const
{
	return m_qualifier;
}

shared_node declaration_node::get_expr() const
{
	return m_expr;
}
