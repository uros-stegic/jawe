#include <increment.hpp>

using namespace jawe;

Increment::Increment(Expr* operand)
	: UnaryOperator(operand, "++", TIncrement)
{}

