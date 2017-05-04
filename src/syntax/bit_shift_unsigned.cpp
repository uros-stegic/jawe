#include <operators/bit_shift_unsigned.hpp>

using namespace jawe;

BitShiftUnsigned::BitShiftUnsigned(Expr* left, Expr* right)
	: BinaryOperator(left, right, ">>>", TBitShiftUnsigned)
{}

