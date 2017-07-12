#include <control_flow/if_else.hpp>

using namespace jawe;

IfElse::IfElse(Expr *expr, Command *if_command, Command *else_command)
	: Command(TIfElse)
	, m_expr(expr)
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
	out << " ) {" << std::endl;
	m_if->print(out);
	out << "}";
	if( m_else != nullptr ) {
		out << "else {" << std::endl;
		m_else->print(out);
		out << "}";
	}
	out << std::endl;
}

void IfElse::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "if-else" << std::endl;
	m_expr->dump_ast(out, tabs+1);
	m_if->dump_ast(out, tabs+1);
	if( m_else != nullptr ) {
		m_else->dump_ast(out, tabs+1);
	}
}

Expr* IfElse::get_expr() const
{
	return m_expr;
}
Command* IfElse::get_if() const
{
	return m_if;
}
Command* IfElse::get_else() const
{
	return m_else;
}

IfElse* IfElse::copy()
{
	return new IfElse(
		m_expr->copy(),
		m_if->copy(),
		(m_else == nullptr) ? nullptr : m_else->copy());
}

