#include <operators/assign_mul.hpp>

using namespace jawe;

AssignMul::AssignMul(Variable* left, Expr* right)
	: BinaryOperator(left, right, "*=", TAssign)
{}

