#include <operators/increment.hpp>

using namespace jawe;

Increment::Increment(Expr* operand)
	: UnaryOperator(operand, "++", TIncrement)
{}

