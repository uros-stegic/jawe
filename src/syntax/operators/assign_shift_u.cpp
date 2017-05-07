#include <operators/assign_shift_u.hpp>

using namespace jawe;

AssignShiftU::AssignShiftU(Expr* left, Expr* right)
	: BinaryOperator(left, right, ">>>=", TAssign)
{}

