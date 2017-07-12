#include <command.hpp>

using namespace jawe;

Command::Command(CommandType type)
	: m_type(type)
	, m_parent(nullptr)
{}
CommandType Command::get_type() const
{
	return m_type;
}

void Command::set_parent(Command* command)
{
	m_parent = command;
}
Command* Command::get_parent() const
{
	return m_parent;
}

