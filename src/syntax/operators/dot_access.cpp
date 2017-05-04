#include <operators/dot_access.hpp>

using namespace jawe;

DotAccess::DotAccess(Expr* left, Expr* right)
	: BinaryOperator(left, right, ".", TDotAccess)
{}

void DotAccess::print(std::ostream& out) const
{
	left()->print(out);
	out << ".";
	right()->print(out);
}

