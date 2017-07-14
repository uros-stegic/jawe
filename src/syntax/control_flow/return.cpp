#include <control_flow/return.hpp>

using namespace jawe;

Return::Return(Expr *expr)
	: Command(TReturn)
	, m_expr(expr)
{}

Return::~Return()
{
	delete m_expr;
}

void Return::print(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "return ";
	m_expr->print(out, tabs);
	out << ";";
}

void Return::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "return " << memory_address() << std::endl;
	m_expr->dump_ast(out, tabs+1);
}

Return* Return::copy()
{
	auto expr = m_expr->copy();
	auto result = new Return(expr);
	expr->set_parent(result);
	return result;
}

