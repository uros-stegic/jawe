#include <literals/false.hpp>

using namespace jawe;

False::False()
{}

False::~False()
{}

void False::print(std::ostream& out) const
{
	out << "false";
}

bool False::value() const
{
	return false;
}

