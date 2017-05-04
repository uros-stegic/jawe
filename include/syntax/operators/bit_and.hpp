#ifndef __BIT_AND_HPP__
#define __BIT_AND_HPP__

#include <operators/binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class BitAnd : public BinaryOperator {
public:
	BitAnd(Expr*, Expr*);
};
}

#endif // __BIT_AND_HPP__

