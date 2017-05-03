#include <times.hpp>

using namespace jawe;

Times::Times(Expr* left, Expr* right)
	: BinaryOperator(left, right, "*", TTimes)
{}

