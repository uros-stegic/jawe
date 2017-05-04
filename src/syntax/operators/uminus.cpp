#include <operators/uminus.hpp>

using namespace jawe;

UMinus::UMinus(Expr* operand)
	: UnaryOperator(operand, "-", TUMinus)
{}

