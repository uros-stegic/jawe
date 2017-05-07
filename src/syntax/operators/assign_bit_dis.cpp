#include <operators/assign_bit_dis.hpp>

using namespace jawe;

AssignBitDis::AssignBitDis(Variable* left, Expr* right)
	: BinaryOperator(left, right, "|=", TAssign)
{}

