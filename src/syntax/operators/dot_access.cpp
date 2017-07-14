#include <operators/dot_access.hpp>

using namespace jawe;

DotAccess::DotAccess(Expr* left, Expr* right)
	: BinaryOperator(left, right, ".", TDotAccess)
{}

void DotAccess::print(std::ostream& out, int tabs) const
{
	if( get_parent()->get_type() == TCommandBlock ) {
		out << std::string(4*tabs, ' ');
	}
	left()->print(out, tabs+1);
	out << ".";
	right()->print(out, tabs+1);
}

