#include <literals/false.hpp>

using namespace jawe;

False::False()
{}

False::~False()
{}

void False::print(std::ostream& out, int tabs) const
{
	out << "false";
}

void False::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "false " << memory_address() << std::endl;
}

bool False::value() const
{
	return false;
}

False* False::copy()
{
	return new False;
}

