#include <literals/undefined.hpp>

using namespace jawe;

Undefined::Undefined()
{}

Undefined::~Undefined()
{}

void Undefined::print(std::ostream& out) const
{
	out << "undefined";
}

