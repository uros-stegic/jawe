#ifndef __ASSIGN_SHIFT_U_HPP__
#define __ASSIGN_SHIFT_U_HPP__

#include <operators/binary_operator.hpp>

namespace jawe {
class AssignShiftU : public BinaryOperator {
public:
	AssignShiftU(Expr*, Expr*);
};
}

#endif // __ASSIGN_SHIFT_U_HPP__

