#include <control_flow/case.hpp>

using namespace jawe;

Case::Case(Primitive *p, Command *command)
	: Command(TCase)
	, m_case(p)
	, m_command(command)
{}

Case::~Case()
{
	delete m_case;
	delete m_command;
}

void Case::print(std::ostream& out) const
{
	out << "case ";
	m_case->print(out);
	out << ": ";
	m_command->print(out);
	out << std::endl;
}

void Case::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "Case [" << this << ": from <" << get_parent() << ">]" << std::endl;
	m_case->dump_ast(out, tabs+1);
	m_command->dump_ast(out, tabs+1);
}

Command* Case::get_body() const
{
	return m_command;
}

Case* Case::copy()
{
	auto c_cpy = m_case->copy();
	auto m_cpy = m_command->copy();
	auto result = new Case(c_cpy, m_cpy);
	c_cpy->set_parent(result);
	m_cpy->set_parent(result);
	return result;
}

