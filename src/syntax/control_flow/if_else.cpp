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
		out << std::endl << "else {" << std::endl;
		m_else->print(out);
		out << "}";
	}
}

void IfElse::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "if-else [" << this << ": from <" << get_parent() << ">]" << std::endl;
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
	auto expr = m_expr->copy();
	auto body = m_if->copy();
	auto alter = (m_else == nullptr) ? nullptr : m_else->copy();

	auto result = new IfElse(expr, body, alter);

	expr->set_parent(result); 
	body->set_parent(result);	
	if( alter ) {
		alter->set_parent(result);
	}

	return result;
}

