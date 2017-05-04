#include <operators/bit_and.hpp>

using namespace jawe;

BitAnd::BitAnd(Expr* left, Expr* right)
	: BinaryOperator(left, right, "&", TBitAnd)
{}

