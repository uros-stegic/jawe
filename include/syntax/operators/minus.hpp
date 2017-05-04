#ifndef __MINUS_HPP__
#define __MINUS_HPP__

#include <operators/binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class Minus : public BinaryOperator {
public:
	Minus(Expr*, Expr*);
};
}

#endif // __MINUS_HPP__

