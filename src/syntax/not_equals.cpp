#include <operators/not_equals.hpp>

using namespace jawe;

NotEquals::NotEquals(Expr* left, Expr* right)
	: BinaryOperator(left, right, "!=", TNotEquals)
{}

