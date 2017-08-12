#include <control_flow/command_block_node.hpp>
#include <algorithm>

using namespace jawe;

command_block_node::command_block_node()
	: basic_node("command_block")
{}
command_block_node::command_block_node(const shared_node& command)
	: basic_node("command_block")
	, m_commands(std::vector<shared_node>{command})
{}

command_block_node::command_block_node(const std::vector<shared_node>& commands)
	: basic_node("command_block")
	, m_commands(commands)
{}

void command_block_node::push_back(const shared_node& other)
{
	m_commands.push_back(other);
}

std::vector<shared_node> command_block_node::get_commands()
{
	return m_commands;
}

void command_block_node::remove(const shared_node& node)
{
	m_commands.erase(std::remove(std::begin(m_commands), std::end(m_commands), node), std::end(m_commands));
}
