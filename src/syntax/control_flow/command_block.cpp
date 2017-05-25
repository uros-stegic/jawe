#include <control_flow/command_block.hpp>
#include <algorithm>

using namespace jawe;

CommandBlock::CommandBlock()
{}
CommandBlock::CommandBlock(Command* command)
	: m_commands(std::vector<Command*>{command})
{}
CommandBlock::CommandBlock(const std::vector<Command*>& commands)
	: m_commands(commands)
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

void CommandBlock::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "command-block" << std::endl;
	std::for_each(
		std::begin(m_commands),
		std::end(m_commands),
		[&](Command* command) {
			command->dump_ast(out, tabs+1);
		}
	);
}

