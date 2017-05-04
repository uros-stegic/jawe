#include <control_flow/for.hpp>

using namespace jawe;

For::For(Command *init, Expr *cond, Command *post, Command *body)
	: m_init(init)
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

