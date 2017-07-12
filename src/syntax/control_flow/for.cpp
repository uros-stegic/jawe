#include <control_flow/for.hpp>

using namespace jawe;

For::For(Command *init, Expr *cond, Command *post, Command *body)
	: Command(TFor)
	, m_init(init)
	, m_cond(cond)
	, m_post(post)
	, m_body(body)
{}

For::~For()
{
	delete m_init;
	delete m_cond;
	delete m_post;
	delete m_body;
}

void For::print(std::ostream& out) const
{
	out << "for(";
	m_init->print(out);
	out << "; ";
	m_cond->print(out);
	out << "; ";
	m_post->print(out);
	out << ")" << std::endl;
	m_body->print(out);
	out << std::endl;
}

void For::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "for" << std::endl;
	m_init->dump_ast(out, tabs+1);
	m_cond->dump_ast(out, tabs+1);
	m_post->dump_ast(out, tabs+1);
	m_body->dump_ast(out, tabs+1);
}

Expr* For::get_expr() const
{
	return m_cond;
}

Command* For::get_body() const
{
	return m_body;
}

Command* For::get_init() const
{
	return m_init;
}

Command* For::get_post() const
{
	return m_post;
}

For* For::copy()
{
	return new For(
		m_init->copy(),
		m_cond->copy(),
		m_post->copy(),
		m_body->copy()
	);
}

