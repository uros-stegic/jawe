#include <operators/minus.hpp>

using namespace jawe;

Minus::Minus(Expr* left, Expr* right)
	: BinaryOperator(left, right, "-", TMinus)
{}

