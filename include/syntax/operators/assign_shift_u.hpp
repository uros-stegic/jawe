#ifndef __ASSIGN_SHIFT_U_HPP__
#define __ASSIGN_SHIFT_U_HPP__

#include <operators/binary_operator.hpp>
#include <variables/variable.hpp>

namespace jawe {
class AssignShiftU : public BinaryOperator {
public:
	AssignShiftU(Variable*, Expr*);
};
}

#endif // __ASSIGN_SHIFT_U_HPP__

