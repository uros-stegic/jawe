#ifndef __ASSIGN_SHIFT_L_HPP__
#define __ASSIGN_SHIFT_L_HPP__

#include <operators/binary_operator.hpp>
#include <variables/variable.hpp>

namespace jawe {
class AssignShiftL : public BinaryOperator {
public:
	AssignShiftL(Variable*, Expr*);
};
}

#endif // __ASSIGN_SHIFT_L_HPP__

