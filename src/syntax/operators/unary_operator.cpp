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

void UnaryOperator::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "operator [" << symbol() << "] [" << this << ": from <" << get_parent() << ">]" << std::endl;
	m_operand->dump_ast(out, tabs+1);
}

Expr* UnaryOperator::operand() const
{
	return m_operand;
}

UnaryOperator* UnaryOperator::copy()
{
	auto operand = m_operand->copy();
	auto result = new UnaryOperator(operand, symbol(), priority());
	operand->set_parent(result);
	return result;
}

