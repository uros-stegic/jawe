#include <operators/delete.hpp>

using namespace jawe;

Delete::Delete(Expr* operand)
	: UnaryOperator(operand, "delete", TDelete)
{}

void Delete::print(std::ostream& out) const
{
	out << "delete ";
	if( priority() < operand()->priority() ) {
		out << "(";
	}
	operand()->print(out);
	if( priority() < operand()->priority() ) {
		out << ")";
	}
}

