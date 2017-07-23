#include <operators/operator_node.hpp>

using namespace jawe;

operator_node::operator_node(std::string symbol)
	: expr_node(symbol)
	, m_symbol(symbol)
{}

