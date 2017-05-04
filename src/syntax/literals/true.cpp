#include <literals/true.hpp>

using namespace jawe;

True::True()
{}

True::~True()
{}

void True::print(std::ostream& out) const
{
	out << "true";
}

bool True::value() const
{
	return true;
}

