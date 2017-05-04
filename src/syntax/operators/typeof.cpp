#include <operators/typeof.hpp>

using namespace jawe;

TypeOf::TypeOf(Expr* operand)
	: UnaryOperator(operand, "typeof", TTypeOf)
{}

void TypeOf::print(std::ostream& out) const
{
	out << "typeof ";
	if( priority() < operand()->priority() ) {
		out << "(";
	}
	operand()->print(out);
	if( priority() < operand()->priority() ) {
		out << ")";
	}
}

