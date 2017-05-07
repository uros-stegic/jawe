#include <operators/assign_div.hpp>

using namespace jawe;

AssignDiv::AssignDiv(Expr* left, Expr* right)
	: BinaryOperator(left, right, "/=", TAssign)
{}

