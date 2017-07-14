#include <control_flow/empty.hpp>

using namespace jawe;

Empty::Empty()
	: Command(TEmpty)
{}

Empty::~Empty()
{}

void Empty::print(std::ostream& out, int tabs) const
{
	out << "/*<empty>*/;";
}

void Empty::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "Empty " << memory_address() << std::endl;
}

Empty* Empty::copy()
{
	return new Empty();
}

