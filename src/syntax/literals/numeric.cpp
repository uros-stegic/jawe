#include <literals/numeric.hpp>

using namespace jawe;

Numeric::Numeric(double value)
	: m_value(value)
{}

Numeric::~Numeric()
{}

void Numeric::print(std::ostream& out) const
{
	out << m_value;
}

void Numeric::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ')
		<< "Number [" << m_value << "]" << std::endl;
}

double Numeric::value() const
{
	return m_value;
}

Numeric* Numeric::copy()
{
	return new Numeric(m_value);
}

