#include <literals/null.hpp>

using namespace jawe;

Null::Null()
{}

Null::~Null()
{}

void Null::print(std::ostream& out) const
{
	out << "null";
}

