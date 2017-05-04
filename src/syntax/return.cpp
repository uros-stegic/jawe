#include <return.hpp>

using namespace jawe;

Return::Return(Expr *expr)
	: m_expr(expr)
{}

Return::~Return()
{
	delete m_expr;
}

void Return::print(std::ostream& out) const
{
	out << "return ";
	m_expr->print(out);
	out << ";" << std::endl;
}

