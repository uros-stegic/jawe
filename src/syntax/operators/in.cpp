#include <operators/in.hpp>

using namespace jawe;

In::In(Expr* left, Expr* right)
	: BinaryOperator(left, right, "in", TIn)
{}

