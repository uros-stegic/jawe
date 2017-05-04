#include <operators/bit_shift_left.hpp>

using namespace jawe;

BitShiftLeft::BitShiftLeft(Expr* left, Expr* right)
	: BinaryOperator(left, right, "<<", TBitShiftLeft)
{}

