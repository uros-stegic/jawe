#include <operators/assign_div.hpp>

using namespace jawe;

AssignDiv::AssignDiv(Variable* left, Expr* right)
	: BinaryOperator(left, right, "/=", TAssign)
{}

