#ifndef __BIT_SHIFT_RIGHT_HPP__
#define __BIT_SHIFT_RIGHT_HPP__

#include <operators/binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class BitShiftRight : public BinaryOperator {
public:
	BitShiftRight(Expr*, Expr*);
};
}

#endif // __BIT_SHIFT_RIGHT_HPP__

