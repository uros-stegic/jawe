#include <operators/assign_minus.hpp>

using namespace jawe;

AssignMinus::AssignMinus(Expr* left, Expr* right)
	: BinaryOperator(left, right, "-=", TAssign)
{}

