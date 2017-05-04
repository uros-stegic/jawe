#include <operators/logic_and.hpp>

using namespace jawe;

LogicAnd::LogicAnd(Expr* left, Expr* right)
	: BinaryOperator(left, right, "&&", TLogicAnd)
{}

