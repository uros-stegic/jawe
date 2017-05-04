#include <operators/plus.hpp>

using namespace jawe;

Plus::Plus(Expr* left, Expr* right)
	: BinaryOperator(left, right, "+", TPlus)
{}

