#ifndef __POWER_HPP__
#define __POWER_HPP__

#include <operators/binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class Power : public BinaryOperator {
public:
	Power(Expr*, Expr*);
};
}

#endif // __POWER_HPP__

