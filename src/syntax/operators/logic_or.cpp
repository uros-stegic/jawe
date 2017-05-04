#include <operators/logic_or.hpp>

using namespace jawe;

LogicOr::LogicOr(Expr* left, Expr* right)
	: BinaryOperator(left, right, "||", TLogicOr)
{}

