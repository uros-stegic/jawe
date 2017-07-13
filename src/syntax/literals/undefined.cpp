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

void Undefined::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "undefined [" << this << ": from <" << get_parent() << ">]" << std::endl;
}

Undefined* Undefined::copy()
{
	return new Undefined();
}

