#include <operators/greater_or_equals.hpp>

using namespace jawe;

GreaterOrEquals::GreaterOrEquals(Expr* left, Expr* right)
	: BinaryOperator(left, right, ">=", TGreaterOrEquals)
{}

