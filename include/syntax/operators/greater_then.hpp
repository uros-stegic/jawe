#ifndef __GREATER_THEN_HPP__
#define __GREATER_THEN_HPP__

#include <operators/binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class GreaterThen : public BinaryOperator {
public:
	GreaterThen(Expr*, Expr*);
};
}

#endif // __GREATER_THEN_HPP__

