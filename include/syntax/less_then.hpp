#ifndef __LESS_THEN_HPP__
#define __LESS_THEN_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class LessThen : public BinaryOperator {
public:
	LessThen(Expr*, Expr*);
};
}

#endif // __LESS_THEN_HPP__

