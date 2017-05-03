#include <post_decrement.hpp>

using namespace jawe;

PostDecrement::PostDecrement(Expr* operand)
	: UnaryOperator(operand, "--", TPostDecrement)
{}

