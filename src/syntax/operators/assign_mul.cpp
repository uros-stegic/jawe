#include <operators/assign_mul.hpp>

using namespace jawe;

AssignMul::AssignMul(Expr* left, Expr* right)
	: BinaryOperator(left, right, "*=", TAssign)
{}

