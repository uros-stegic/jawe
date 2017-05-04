#include <do_while.hpp>

using namespace jawe;

DoWhile::DoWhile(Command *body, Expr *cond)
	: m_body(body)
	, m_cond(cond)
{}

DoWhile::~DoWhile()
{
	delete m_body;
	delete m_cond;
}

void DoWhile::print(std::ostream& out) const
{
	out << "do" << std::endl;
	m_body->print(out);
	out << "while( ";
	m_cond->print(out);
	out << " );" << std::endl;
	out << std::endl;
}

