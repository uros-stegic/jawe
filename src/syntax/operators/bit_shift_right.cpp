#include <operators/bit_shift_right.hpp>

using namespace jawe;

BitShiftRight::BitShiftRight(Expr* left, Expr* right)
	: BinaryOperator(left, right, ">>", TBitShiftRight)
{}

