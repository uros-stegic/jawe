#include <control_flow/continue.hpp>

using namespace jawe;

Continue::Continue()
	: Command(TContinue)
{}

Continue::~Continue()
{}

void Continue::print(std::ostream& out) const
{
	out << "continue;" << std::endl;
}

void Continue::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "continue " << memory_address() << std::endl;
}

Continue* Continue::copy()
{
	return new Continue();
}

