#ifndef __ASSIGN_MUL_HPP__
#define __ASSIGN_MUL_HPP__

#include <operators/binary_operator.hpp>

namespace jawe {
class AssignMul : public BinaryOperator {
public:
	AssignMul(Expr*, Expr*);
};
}

#endif // __ASSIGN_MUL_HPP__

