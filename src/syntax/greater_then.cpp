#include <greater_then.hpp>

using namespace jawe;

GreaterThen::GreaterThen(Expr* left, Expr* right)
	: BinaryOperator(left, right, ">", TGreaterThen)
{}

