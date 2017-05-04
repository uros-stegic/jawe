#ifndef __POST_INCREMENT_HPP__
#define __POST_INCREMENT_HPP__

#include <operators/unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class PostIncrement : public UnaryOperator {
public:
	PostIncrement(Expr*);
};
}

#endif // __POST_INCREMENT_HPP__

