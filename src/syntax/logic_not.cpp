#include <logic_not.hpp>

using namespace jawe;

LogicNot::LogicNot(Expr* operand)
	: UnaryOperator(operand, "!", TLogicNot)
{}

