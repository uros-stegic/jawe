#include <operators/delete.hpp>

using namespace jawe;

Delete::Delete(Expr* operand)
	: UnaryOperator(operand, "delete", TDelete)
{}

