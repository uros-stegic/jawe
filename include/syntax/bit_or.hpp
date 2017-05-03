#ifndef __BIT_OR_HPP__
#define __BIT_OR_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class BitOr : public BinaryOperator {
public:
	BitOr(Expr*, Expr*);
};
}

#endif // __BIT_OR_HPP__

