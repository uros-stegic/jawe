#include <expr.hpp>

using namespace jawe;

Expr::Expr(const Priority& P)
	: m_priority(P)
{}

Priority Expr::priority() const
{
	return m_priority;
}

