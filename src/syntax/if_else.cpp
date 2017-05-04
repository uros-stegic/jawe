#include <if_else.hpp>

using namespace jawe;

IfElse::IfElse(Expr *expr, Command *if_command, Command *else_command)
	: m_expr(expr)
	, m_if(if_command)
	, m_else(else_command)
{}

IfElse::~IfElse()
{
	delete m_expr;
	delete m_if;
	delete m_else;
}

void IfElse::print(std::ostream& out) const
{
	out << "if( ";
	m_expr->print(out);
	out << " )" << std::endl;
	m_if->print(out);
	out << std::endl;
	if( m_else != nullptr ) {
		out << "else" << std::endl;
		m_else->print(out);
		out << std::endl;
	}
}

