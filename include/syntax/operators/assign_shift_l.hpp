#ifndef __ASSIGN_SHIFT_L_HPP__
#define __ASSIGN_SHIFT_L_HPP__

#include <operators/binary_operator.hpp>

namespace jawe {
class AssignShiftL : public BinaryOperator {
public:
	AssignShiftL(Expr*, Expr*);
};
}

#endif // __ASSIGN_SHIFT_L_HPP__

