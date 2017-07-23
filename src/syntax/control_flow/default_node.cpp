#include <control_flow/default_node.hpp>

using namespace jawe;

default_node::default_node(const shared_node& command)
	: basic_node("default")
	, m_command(command)
{}

shared_node default_node::get_body() const
{
	return m_command;
}

