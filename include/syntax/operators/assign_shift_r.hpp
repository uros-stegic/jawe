#ifndef __ASSIGN_SHIFT_R_HPP__
#define __ASSIGN_SHIFT_R_HPP__

#include <operators/binary_operator.hpp>

namespace jawe {
class AssignShiftR : public BinaryOperator {
public:
	AssignShiftR(Expr*, Expr*);
};
}

#endif // __ASSIGN_SHIFT_R_HPP__

