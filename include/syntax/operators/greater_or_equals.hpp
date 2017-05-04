#ifndef __GREATER_OR_EQUALS_HPP__
#define __GREATER_OR_EQUALS_HPP__

#include <operators/binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class GreaterOrEquals : public BinaryOperator {
public:
	GreaterOrEquals(Expr*, Expr*);
};
}

#endif // __GREATER_OR_EQUALS_HPP__

