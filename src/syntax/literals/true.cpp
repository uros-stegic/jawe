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

void True::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "true [" << this << ": from <" << get_parent() << ">]" << std::endl;
}

bool True::value() const
{
	return true;
}

True* True::copy()
{
	return new True();
}

