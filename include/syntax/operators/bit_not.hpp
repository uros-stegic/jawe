#ifndef __BIT_NOT_HPP__
#define __BIT_NOT_HPP__

#include <operators/unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class BitNot : public UnaryOperator {
public:
	BitNot(Expr*);
};
}

#endif // __BIT_NOT_HPP__

