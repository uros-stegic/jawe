#ifndef __BIT_SHIFT_LEFT_HPP__
#define __BIT_SHIFT_LEFT_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class BitShiftLeft : public BinaryOperator {
public:
	BitShiftLeft(Expr*, Expr*);
};
}

#endif // __BIT_SHIFT_LEFT_HPP__

