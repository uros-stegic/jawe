#include <operators/assign_plus.hpp>

using namespace jawe;

AssignPlus::AssignPlus(Expr* left, Expr* right)
	: BinaryOperator(left, right, "+=", TAssign)
{}

