#include <typed_equals.hpp>

using namespace jawe;

TypedEquals::TypedEquals(Expr* left, Expr* right)
	: BinaryOperator(left, right, "===", TTypedEquals)
{}

