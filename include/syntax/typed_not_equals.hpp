#ifndef __TYPED_NOT_EQUALS_HPP__
#define __TYPED_NOT_EQUALS_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class TypedNotEquals : public BinaryOperator {
public:
	TypedNotEquals(Expr*, Expr*);
};
}

#endif // __TYPED_NOT_EQUALS_HPP__

