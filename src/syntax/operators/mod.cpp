#include <operators/mod.hpp>

using namespace jawe;

Mod::Mod(Expr* left, Expr* right)
	: BinaryOperator(left, right, "%", TMod)
{}

