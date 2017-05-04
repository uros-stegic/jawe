#include <operators/decrement.hpp>

using namespace jawe;

Decrement::Decrement(Expr* operand)
	: UnaryOperator(operand, "--", TDecrement)
{}

