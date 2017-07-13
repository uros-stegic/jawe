#include <operators/ternary_operator.hpp>

using namespace jawe;

TernaryOperator::TernaryOperator(
	Expr* first_operand,
	Expr* second_operand,
	Expr* third_operand,
	std::string symbol,
	std::string symbol2,
	const Priority& priority
)
	: Operator(symbol, priority)
	, m_first(first_operand)
	, m_second(second_operand)
	, m_third(third_operand)
	, m_symbol2(symbol2)
{}

TernaryOperator::~TernaryOperator()
{
	delete m_first;
	delete m_second;
	delete m_third;
}

void TernaryOperator::print(std::ostream& out) const
{
	out << "(";
	m_first->print(out);
	out << ")";

	out << " " << symbol() << " ";

	m_second->print(out);

	out << " " << m_symbol2 << " ";

	m_third->print(out);
}
void TernaryOperator::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ')
		<< "operator ["
		<< symbol()
		<< " "
		<< m_symbol2
		<< "] " << memory_address()
		<< std::endl;
	m_first->dump_ast(out, tabs+1);
	m_second->dump_ast(out, tabs+1);
	m_third->dump_ast(out, tabs+1);
}

Expr* TernaryOperator::first_operand() const
{
	return m_first;
}

Expr* TernaryOperator::second_operand() const
{
	return m_second;
}

Expr* TernaryOperator::third_operand() const
{
	return m_third;
}

TernaryOperator* TernaryOperator::copy()
{
	auto first = m_first->copy();
	auto second = m_second->copy();
	auto third = m_third->copy();
	auto result = new TernaryOperator(
		first,
		second,
		third,
		symbol(),
		m_symbol2,
		priority()
	);
	first ->set_parent(result); 
	second->set_parent(result);
	third ->set_parent(result);
	return result;
}

