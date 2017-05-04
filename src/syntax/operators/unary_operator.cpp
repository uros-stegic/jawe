#include <operators/unary_operator.hpp>

using namespace jawe;

UnaryOperator::UnaryOperator(Expr* operand, std::string symbol, const Priority& priority)
	: Operator(symbol, priority)
	, m_operand(operand)
{}

UnaryOperator::~UnaryOperator()
{
	delete m_operand;
}

void UnaryOperator::print(std::ostream& out) const
{
	out << symbol();
	if( m_operand->priority() < priority() ) {
		out << "(";
	}
	m_operand->print(out);
	if( m_operand->priority() < priority() ) {
		out << ")";
	}
}

Expr* UnaryOperator::operand() const
{
	return m_operand;
}

