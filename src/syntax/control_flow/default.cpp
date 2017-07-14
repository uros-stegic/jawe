#include <control_flow/default.hpp>

using namespace jawe;

Default::Default(Command *command)
	: Command(TDefault)
	, m_command(command)
{}

Default::~Default()
{
	delete m_command;
}

void Default::print(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "default: ";
	m_command->print(out, tabs+1);
	out << std::endl;
}

void Default::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "Default " << memory_address() << std::endl;
	m_command->dump_ast(out, tabs+1);
}

Command* Default::get_body() const
{
	return m_command;
}

Default* Default::copy()
{
	auto cpy = m_command->copy();
	auto result = new Default(cpy);
	cpy->set_parent(result);
	return result;
}

