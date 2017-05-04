#ifndef __INCREMENT_HPP__
#define __INCREMENT_HPP__

#include <operators/unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class Increment : public UnaryOperator {
public:
	Increment(Expr*);
};
}

#endif // __INCREMENT_HPP__

