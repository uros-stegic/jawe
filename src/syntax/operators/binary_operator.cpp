#include <operators/binary_operator.hpp>

using namespace jawe;

BinaryOperator::BinaryOperator(Expr* left, Expr* right, std::string symbol, const Priority& priority)
	: Operator(symbol, priority)
	, m_left(left)
	, m_right(right)
{}

BinaryOperator::~BinaryOperator()
{
	delete m_left;
	delete m_right;
}

void BinaryOperator::print(std::ostream& out) const {
	if( m_left->priority() < priority() ) {
		out << "(";
	}
	m_left->print(out);
	if( m_left->priority() < priority() ) {
		out << ")";
	}

	out << " " << symbol() << " ";

	if( m_right->priority() < priority() ) {
		out << "(";
	}
	m_right->print(out);
	if( m_right->priority() < priority() ) {
		out << ")";
	}
}

Expr* BinaryOperator::left() const
{
	return m_left;
}

Expr* BinaryOperator::right() const
{
	return m_right;
}

