#include <divide.hpp>

using namespace jawe;

Divide::Divide(Expr* left, Expr* right)
	: BinaryOperator(left, right, "/", TDivide)
{}

