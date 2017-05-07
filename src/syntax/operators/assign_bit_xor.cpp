#include <operators/assign_bit_xor.hpp>

using namespace jawe;

AssignBitXor::AssignBitXor(Variable* left, Expr* right)
	: BinaryOperator(left, right, "^=", TAssign)
{}

