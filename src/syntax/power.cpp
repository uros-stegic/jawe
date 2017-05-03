#include <power.hpp>

using namespace jawe;

Power::Power(Expr* left, Expr* right)
	: BinaryOperator(left, right, "**", TPower)
{}

