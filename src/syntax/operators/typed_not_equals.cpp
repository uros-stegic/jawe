#include <operators/typed_not_equals.hpp>

using namespace jawe;

TypedNotEquals::TypedNotEquals(Expr* left, Expr* right)
	: BinaryOperator(left, right, "!==", TTypedNotEquals)
{}

