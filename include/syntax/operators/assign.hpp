#ifndef __ASSIGN_HPP__
#define __ASSIGN_HPP__

#include <operators/binary_operator.hpp>

namespace jawe {
class Assign : public BinaryOperator {
public:
	Assign(Expr*, Expr*);
};
}

#endif // __ASSIGN_HPP__

