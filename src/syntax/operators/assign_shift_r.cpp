#include <operators/assign_shift_r.hpp>

using namespace jawe;

AssignShiftR::AssignShiftR(Expr* left, Expr* right)
	: BinaryOperator(left, right, ">>=", TAssign)
{}

