#include <operators/typeof.hpp>

using namespace jawe;

TypeOf::TypeOf(Expr* operand)
	: UnaryOperator(operand, "typeof", TTypeOf)
{}

