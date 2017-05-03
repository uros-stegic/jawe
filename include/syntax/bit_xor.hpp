#ifndef __BIT_XOR_HPP__
#define __BIT_XOR_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class BitXor : public BinaryOperator {
public:
	BitXor(Expr*, Expr*);
};
}

#endif // __BIT_XOR_HPP__

