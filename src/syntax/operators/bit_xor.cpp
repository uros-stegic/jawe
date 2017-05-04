#include <operators/bit_xor.hpp>

using namespace jawe;

BitXor::BitXor(Expr* left, Expr* right)
	: BinaryOperator(left, right, "^", TBitXor)
{}

