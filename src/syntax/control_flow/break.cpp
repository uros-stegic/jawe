#include <control_flow/break.hpp>

using namespace jawe;

Break::Break()
	: Command(TBreak)
{}

Break::~Break()
{}

void Break::print(std::ostream& out) const
{
	out << "break;" << std::endl;
}

void Break::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "break [" << this << ": from <" << get_parent() << ">]" << std::endl;
}

Break* Break::copy()
{
	return new Break();
}

