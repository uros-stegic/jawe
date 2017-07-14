#include <control_flow/break.hpp>

using namespace jawe;

Break::Break()
	: Command(TBreak)
{}

Break::~Break()
{}

void Break::print(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "break;";
}

void Break::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "break " << memory_address() << std::endl;
}

Break* Break::copy()
{
	return new Break();
}

