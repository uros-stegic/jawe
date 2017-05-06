#include <control_flow/return.hpp>

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

void Return::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "return" << std::endl;
	m_expr->dump_ast(out, tabs+1);
}

