#include <ternary_conditional.hpp>

using namespace jawe;

TernaryConditional::TernaryConditional(Expr* first, Expr* second, Expr* third)
	: TernaryOperator(first, second, third, "?", ":", TTernaryConditional)
{}

