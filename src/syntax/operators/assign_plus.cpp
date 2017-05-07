#include <operators/assign_plus.hpp>

using namespace jawe;

AssignPlus::AssignPlus(Variable* left, Expr* right)
	: BinaryOperator(left, right, "+=", TAssign)
{}

