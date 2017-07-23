#include <operators/function_call_node.hpp>
#include <algorithm>

using namespace jawe;

function_call_node::function_call_node(const shared_node& expr)
	: expr_node("function_call")
	, m_expr(expr)
{}

function_call_node::function_call_node(const shared_node& expr, const std::vector<shared_node>& args)
	: expr_node("function_call")
	, m_expr(expr)
	, m_args(args)
{}

void function_call_node::push_back(const shared_node& expr)
{
	m_args.push_back(expr);
}

