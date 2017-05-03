#ifndef __POST_DECREMENT_HPP__
#define __POST_DECREMENT_HPP__

#include <unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class PostDecrement : public UnaryOperator {
public:
	PostDecrement(Expr*);
};
}

#endif // __POST_DECREMENT_HPP__

