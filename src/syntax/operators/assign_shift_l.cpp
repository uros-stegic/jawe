#include <operators/assign_shift_l.hpp>

using namespace jawe;

AssignShiftL::AssignShiftL(Variable* left, Expr* right)
	: BinaryOperator(left, right, "<<=", TAssign)
{}

