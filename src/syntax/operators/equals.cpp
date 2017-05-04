#include <operators/equals.hpp>

using namespace jawe;

Equals::Equals(Expr* left, Expr* right)
	: BinaryOperator(left, right, "==", TEquals)
{}

