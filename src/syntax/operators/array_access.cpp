#include <operators/array_access.hpp>

using namespace jawe;

ArrayAccess::ArrayAccess(Expr* left, Expr* right)
	: BinaryOperator(left, right, "[]", TArrayAccess)
{}

void ArrayAccess::print(std::ostream& out, int tabs) const
{
	if( get_parent()->get_type() == TCommandBlock ) {
		out << std::string(4*tabs, ' ');
	}
	left()->print(out, tabs+1);
	out << "[";
	right()->print(out, tabs+1);
	out << "]";
}

