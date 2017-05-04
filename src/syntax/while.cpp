#include <while.hpp>

using namespace jawe;

While::While(Expr *cond, Command *body)
	: m_cond(cond)
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

