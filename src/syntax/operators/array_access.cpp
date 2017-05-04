#include <operators/array_access.hpp>

using namespace jawe;

ArrayAccess::ArrayAccess(Expr* left, Expr* right)
	: BinaryOperator(left, right, "[]", TArrayAccess)
{}

void ArrayAccess::print(std::ostream& out) const
{
	left()->print(out);
	out << "[";
	right()->print(out);
	out << "]";
}

