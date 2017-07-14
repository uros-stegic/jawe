#include <literals/null.hpp>

using namespace jawe;

Null::Null()
{}

Null::~Null()
{}

void Null::print(std::ostream& out, int tabs) const
{
	out << "null";
}

void Null::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "null [" << this << ": from <" << get_parent() << ">]" << std::endl;
}

Null* Null::copy()
{
	return new Null();
}

