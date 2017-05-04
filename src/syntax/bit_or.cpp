#include <operators/bit_or.hpp>

using namespace jawe;

BitOr::BitOr(Expr* left, Expr* right)
	: BinaryOperator(left, right, "|", TBitOr)
{}

