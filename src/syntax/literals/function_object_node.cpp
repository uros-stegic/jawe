#include <literals/function_object_node.hpp>
#include <algorithm>

using namespace jawe;

function_object_node::function_object_node(const std::vector<std::string> &args, const shared_node& body, std::string symbol)
	: abstract_object_node(symbol)
	, m_args(args)
	, m_body(body)
{}

shared_node function_object_node::get_body()
{
	return m_body;
}

std::vector<std::string> function_object_node::get_args()
{
	return m_args;
}
