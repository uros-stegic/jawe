#include <operators/assign_minus.hpp>

using namespace jawe;

AssignMinus::AssignMinus(Variable* left, Expr* right)
	: BinaryOperator(left, right, "-=", TAssign)
{}

