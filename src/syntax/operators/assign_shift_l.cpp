#include <operators/assign_shift_l.hpp>

using namespace jawe;

AssignShiftL::AssignShiftL(Expr* left, Expr* right)
	: BinaryOperator(left, right, "<<=", TAssign)
{}

