#include <operators/uplus.hpp>

using namespace jawe;

UPlus::UPlus(Expr* operand)
	: UnaryOperator(operand, "+", TUPlus)
{}

