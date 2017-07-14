#include <operators/new.hpp>

using namespace jawe;

New::New(Expr* operand)
	: UnaryOperator(operand, "new", TNew)
{}

