#include <post_increment.hpp>

using namespace jawe;

PostIncrement::PostIncrement(Expr* operand)
	: UnaryOperator(operand, "++", TPostIncrement)
{}

