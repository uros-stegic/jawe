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

double Numeric::value() const
{
	return m_value;
}

