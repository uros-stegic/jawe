#ifndef __NOT_EQUALS_HPP__
#define __NOT_EQUALS_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class NotEquals : public BinaryOperator {
public:
	NotEquals(Expr*, Expr*);
};
}

#endif // __NOT_EQUALS_HPP__

