#include <operators/assign.hpp>

using namespace jawe;

Assign::Assign(Expr* left, Expr* right)
	: BinaryOperator(left, right, "=", TAssign)
{}

