#include <control_flow/break.hpp>

using namespace jawe;

Break::Break()
{}

Break::~Break()
{}

void Break::print(std::ostream& out) const
{
	out << "break;" << std::endl;
}

