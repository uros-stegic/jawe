#ifndef __TIMES_HPP__
#define __TIMES_HPP__

#include <operators/binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class Times : public BinaryOperator {
public:
	Times(Expr*, Expr*);
};
}

#endif // __TIMES_HPP__

