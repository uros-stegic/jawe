#ifndef __ASSIGN_MUL_HPP__
#define __ASSIGN_MUL_HPP__

#include <operators/binary_operator.hpp>
#include <variables/variable.hpp>

namespace jawe {
class AssignMul : public BinaryOperator {
public:
	AssignMul(Variable*, Expr*);
};
}

#endif // __ASSIGN_MUL_HPP__

