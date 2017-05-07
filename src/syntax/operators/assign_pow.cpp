#include <operators/assign_pow.hpp>

using namespace jawe;

AssignPow::AssignPow(Expr* left, Expr* right)
	: BinaryOperator(left, right, "**=", TAssign)
{}

