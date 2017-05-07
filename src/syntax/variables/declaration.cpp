#include <variables/declaration.hpp>

using namespace jawe;

Declaration::Declaration(Expr* expr, Qualifier qualifier)
	: m_expr(expr)
	, m_qualifier(qualifier)
{}

Declaration::~Declaration()
{
	delete m_expr;
}

Qualifier Declaration::qualifier() const
{
	return m_qualifier;
}

Expr* Declaration::expr() const
{
	return m_expr;
}

