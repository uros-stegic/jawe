#include <operators/assign_shift_r.hpp>

using namespace jawe;

AssignShiftR::AssignShiftR(Variable* left, Expr* right)
	: BinaryOperator(left, right, ">>=", TAssign)
{}

