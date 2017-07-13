#include <control_flow/command_block.hpp>
#include <algorithm>

using namespace jawe;

CommandBlock::CommandBlock()
	: Command(TCommandBlock)
{}
CommandBlock::CommandBlock(Command* command)
	: Command(TCommandBlock)
	, m_commands(std::vector<Command*>{command})
{}
CommandBlock::CommandBlock(const std::vector<Command*>& commands)
	: Command(TCommandBlock)
	, m_commands(commands)
{}
CommandBlock::~CommandBlock()
{
	for(auto &i: m_commands) {
		delete i;
	}
}

void CommandBlock::print(std::ostream& out) const
{
	std::for_each(
		std::begin(m_commands),
		std::end(m_commands),
		[&](Command* command) {
			command->print(out);
			out << std::endl;
		}
	);
}

void CommandBlock::insert(Command* other)
{
	m_commands.push_back(other);
}

void CommandBlock::prepend(Command* new_command)
{
	m_commands.insert(m_commands.begin(), new_command);
}
void CommandBlock::insert_before(Command* before, Command* new_command)
{
	auto pos = std::find(m_commands.begin(), m_commands.end(), before);
	m_commands.insert(pos, new_command);
}

void CommandBlock::replace(Command* from, Command* to)
{
	auto pos = std::find(m_commands.begin(), m_commands.end(), from);
	if( pos == m_commands.end() ) {
		std::cerr << "WARNING: cannot find " << from->get_type() << std::endl;
		return;
	}
	delete *pos;
	std::swap(*pos, to);
}

void CommandBlock::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "command-block [" << this << ": from <" << get_parent() << ">]" << std::endl;
	std::for_each(
		std::begin(m_commands),
		std::end(m_commands),
		[&](Command* command) {
			command->dump_ast(out, tabs+1);
		}
	);
}

std::vector<Command*>& CommandBlock::get_commands()
{
	return m_commands;
}

CommandBlock* CommandBlock::copy()
{
	auto result = new CommandBlock();
	std::for_each(
		std::begin(m_commands),
		std::end(m_commands),
		[&result](Command* command) {
			auto cmd = command->copy();
			cmd->set_parent(result);
			result->insert(cmd);
		}
	);
	return result;
}

