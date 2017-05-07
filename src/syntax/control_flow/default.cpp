#include <control_flow/default.hpp>

using namespace jawe;

Default::Default(Command *command)
	: m_command(command)
{}

Default::~Default()
{
	delete m_command;
}

void Default::print(std::ostream& out) const
{
	out << "default: ";
	m_command->print(out);
	out << std::endl;
}

void Default::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "Default" << std::endl;
	m_command->dump_ast(out, tabs+1);
}

