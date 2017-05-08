#include <operators/instance_of.hpp>

using namespace jawe;

InstanceOf::InstanceOf(Expr* left, Expr* right)
	: BinaryOperator(left, right, "instanceof", TInstanceOf)
{}

