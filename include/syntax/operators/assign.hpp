#ifndef __ASSIGN_HPP__
#define __ASSIGN_HPP__

#include <operators/binary_operator.hpp>
#include <variables/variable.hpp>

namespace jawe {
class Assign : public BinaryOperator {
public:
	Assign(Variable*, Expr*);
};
}

#endif // __ASSIGN_HPP__

