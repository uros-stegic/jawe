#include <operators/assign_mod.hpp>

using namespace jawe;

AssignMod::AssignMod(Variable* left, Expr* right)
	: BinaryOperator(left, right, "%=", TAssign)
{}

