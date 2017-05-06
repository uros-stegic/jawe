#include <control_flow/do_while.hpp>

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

void DoWhile::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "do-while" << std::endl;
	m_body->dump_ast(out, tabs+1);
	m_cond->dump_ast(out ,tabs+1);
}


