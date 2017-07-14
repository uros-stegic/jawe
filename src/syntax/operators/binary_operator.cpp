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

void BinaryOperator::print(std::ostream& out, int tabs) const
{
	if( get_parent()->get_type() == TCommandBlock ) {
		out << std::string(4*tabs, ' ');
	}
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
}

void BinaryOperator::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "operator [" << symbol() << "] " << memory_address() << std::endl;
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

Expr* BinaryOperator::copy()
{
	auto lft = m_left->copy();
	auto rgh = m_right->copy();
	auto result = new BinaryOperator(lft, rgh, symbol(), priority());
	lft->set_parent(result);
	rgh->set_parent(result);
	return result;
}
