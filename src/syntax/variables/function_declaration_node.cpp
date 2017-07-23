#include <variables/function_declaration_node.hpp>

using namespace jawe;

function_declaration_node::function_declaration_node(std::string name, const function_object_node& f)
	: basic_node(name)
	, m_name(name)
	, m_function_object(f)
{}

shared_node function_declaration_node::get_body()
{
	return m_function_object.get_body();
}

function_object_node function_declaration_node::get_function_object()
{
	return m_function_object;
}

std::string function_declaration_node::get_name() const
{
	return m_name;
}

