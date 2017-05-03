#include <void.hpp>

using namespace jawe;

Void::Void(Expr* operand)
	: UnaryOperator(operand, "void", TVoid)
{}

void Void::print(std::ostream& out) const
{
	out << "void ";
	if( priority() < operand()->priority() ) {
		out << "(";
	}
	operand()->print(out);
	if( priority() < operand()->priority() ) {
		out << ")";
	}
}

