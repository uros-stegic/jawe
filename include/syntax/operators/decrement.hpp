#ifndef __DECREMENT_HPP__
#define __DECREMENT_HPP__

#include <operators/unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class Decrement : public UnaryOperator {
public:
	Decrement(Expr*);
};
}

#endif // __DECREMENT_HPP__

