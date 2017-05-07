#include <operators/assign_bit_con.hpp>

using namespace jawe;

AssignBitCon::AssignBitCon(Expr* left, Expr* right)
	: BinaryOperator(left, right, "&=", TAssign)
{}

