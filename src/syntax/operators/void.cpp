#include <operators/void.hpp>

using namespace jawe;

Void::Void(Expr* operand)
	: UnaryOperator(operand, "void", TVoid)
{}

