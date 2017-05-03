#ifndef __BIT_SHIFT_UNSIGNED_HPP__
#define __BIT_SHIFT_UNSIGNED_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class BitShiftUnsigned : public BinaryOperator {
public:
	BitShiftUnsigned(Expr*, Expr*);
};
}

#endif // __BIT_SHIFT_UNSIGNED_HPP__

