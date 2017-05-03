#include <operator.hpp>

using namespace jawe;

Operator::Operator(std::string symbol, const Priority& priority)
	: Expr(priority)
	, m_symbol(symbol)
{}

std::string Operator::symbol() const
{
	return m_symbol;
}

