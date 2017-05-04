#include <operators/less_or_equals.hpp>

using namespace jawe;

LessOrEquals::LessOrEquals(Expr* left, Expr* right)
	: BinaryOperator(left, right, "<=", TLessOrEquals)
{}

