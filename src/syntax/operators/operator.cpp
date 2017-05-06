#include <operators/operator.hpp>

using namespace jawe;

Operator::Operator(std::string symbol, const Priority& priority)
	: Expr(priority)
	, m_symbol(symbol)
{}

std::string Operator::symbol() const
{
	return m_symbol;
}

void Operator::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "operator [" << m_symbol << "]" << std::endl;
}

