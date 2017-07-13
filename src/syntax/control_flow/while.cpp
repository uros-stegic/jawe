#include <control_flow/while.hpp>

using namespace jawe;

While::While(Expr *cond, Command *body)
	: Command(TWhile)
	, m_cond(cond)
	, m_body(body)
{}

While::~While()
{
	delete m_cond;
	delete m_body;
}

void While::print(std::ostream& out) const
{
	out << "while( ";
	m_cond->print(out);
	out << " )" << std::endl;
	m_body->print(out);
	out << std::endl;
}

void While::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "while [" << this << ": from <" << get_parent() << ">]" << std::endl;
	m_cond->dump_ast(out, tabs+1);
	m_body->dump_ast(out, tabs+1);
}

Expr* While::get_expr() const
{
	return m_cond;
}

Command* While::get_body() const
{
	return m_body;
}

While* While::copy()
{
	auto cond = m_cond->copy();
	auto body = m_body->copy();

	auto result = new While(cond, body);

	cond->set_parent(result);
	body->set_parent(result);

	return result;
}

