#include <operators/assign_bit_xor.hpp>

using namespace jawe;

AssignBitXor::AssignBitXor(Expr* left, Expr* right)
	: BinaryOperator(left, right, "^=", TAssign)
{}

