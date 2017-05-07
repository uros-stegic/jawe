#include <operators/assign_pow.hpp>

using namespace jawe;

AssignPow::AssignPow(Variable* left, Expr* right)
	: BinaryOperator(left, right, "**=", TAssign)
{}

