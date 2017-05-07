#include <operators/assign_mod.hpp>

using namespace jawe;

AssignMod::AssignMod(Expr* left, Expr* right)
	: BinaryOperator(left, right, "%=", TAssign)
{}

