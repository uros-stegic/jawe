#include <less_then.hpp>

using namespace jawe;

LessThen::LessThen(Expr* left, Expr* right)
	: BinaryOperator(left, right, "<", TLessThen)
{}

