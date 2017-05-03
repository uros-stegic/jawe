#include <bit_not.hpp>

using namespace jawe;

BitNot::BitNot(Expr* operand)
	: UnaryOperator(operand, "~", TBitNot)
{}

