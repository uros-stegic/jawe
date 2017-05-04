#include <operators/new.hpp>

using namespace jawe;

New::New(Expr* operand)
	: UnaryOperator(operand, "new", TNew)
{}

void New::print(std::ostream& out) const
{
	out << "new ";
	if( priority() < operand()->priority() ) {
		out << "(";
	}
	operand()->print(out);
	if( priority() < operand()->priority() ) {
		out << ")";
	}
}

