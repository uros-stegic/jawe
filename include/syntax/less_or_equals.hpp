#ifndef __LESS_OR_EQUALS_HPP__
#define __LESS_OR_EQUALS_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class LessOrEquals : public BinaryOperator {
public:
	LessOrEquals(Expr*, Expr*);
};
}

#endif // __LESS_OR_EQUALS_HPP__

