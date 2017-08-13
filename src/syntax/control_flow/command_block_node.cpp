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

void command_block_node::push_back_fun_decl(const shared_node& other)
{
	m_fun_declarations.push_back(other);
}

void command_block_node::push_back_var_decl(const shared_node& other)
{
	m_var_declarations.push_back(other);
}

std::vector<shared_node> command_block_node::get_commands()
{
	auto all_commands = m_fun_declarations;
	all_commands.insert(all_commands.end(), m_var_declarations.begin(), m_var_declarations.end());
	all_commands.insert(all_commands.end(), m_commands.begin(), m_commands.end());
	return all_commands;
}

void command_block_node::remove(const shared_node& node)
{
	remove_command(node);
	remove_fun_decl(node);
	remove_var_decl(node);
}

void command_block_node::remove_command(const shared_node& node)
{
	m_commands.erase(std::remove(std::begin(m_commands), std::end(m_commands), node), std::end(m_commands));
}

void command_block_node::remove_fun_decl(const shared_node& node)
{
	m_fun_declarations.erase(std::remove(std::begin(m_fun_declarations), std::end(m_fun_declarations), node), std::end(m_fun_declarations));
}

void command_block_node::remove_var_decl(const shared_node& node)
{
	m_var_declarations.erase(std::remove(std::begin(m_var_declarations), std::end(m_var_declarations), node), std::end(m_var_declarations));
}

void command_block_node::replace(const shared_node& node, shared_node&& replacement)
{
	auto it = std::find(m_commands.begin(), m_commands.end(), node);
	if(it != m_commands.end()){
		*it = replacement;
	}
}
