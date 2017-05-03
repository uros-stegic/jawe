#ifndef __TYPED_EQUALS_HPP__
#define __TYPED_EQUALS_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class TypedEquals : public BinaryOperator {
public:
	TypedEquals(Expr*, Expr*);
};
}

#endif // __TYPED_EQUALS_HPP__

