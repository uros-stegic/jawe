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

	if( get_parent() != nullptr && get_parent()->get_type() == TCommandBlock ) {
		out << ";";
	}
	else if( get_parent() != nullptr ) {
		out << " <" << get_parent()->get_type() << ">";
	}
	else {
		out << " <nullptr>";
	}
}

void BinaryOperator::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "operator [" << symbol() << "]" << std::endl;
	m_left->dump_ast(out, tabs+1);
	m_right->dump_ast(out, tabs+1);
}

Expr* BinaryOperator::left() const
{
	return m_left;
}

Expr* BinaryOperator::right() const
{
	return m_right;
}

BinaryOperator* BinaryOperator::copy()
{
	return new BinaryOperator(m_left->copy(), m_right->copy(), symbol(), priority());
}

