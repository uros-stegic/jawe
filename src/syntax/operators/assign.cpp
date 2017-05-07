#include <operators/assign.hpp>

using namespace jawe;

Assign::Assign(Variable* left, Expr* right)
	: BinaryOperator(left, right, "=", TAssign)
{}

