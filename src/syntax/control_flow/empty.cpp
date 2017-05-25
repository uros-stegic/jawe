#include <control_flow/empty.hpp>

using namespace jawe;

Empty::Empty()
{}

Empty::~Empty()
{}

void Empty::print(std::ostream& out) const
{
	out << ";";
}

void Empty::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "Empty" << std::endl;
}
