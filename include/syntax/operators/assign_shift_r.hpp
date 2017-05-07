#ifndef __ASSIGN_SHIFT_R_HPP__
#define __ASSIGN_SHIFT_R_HPP__

#include <operators/binary_operator.hpp>
#include <variables/variable.hpp>

namespace jawe {
class AssignShiftR : public BinaryOperator {
public:
	AssignShiftR(Variable*, Expr*);
};
}

#endif // __ASSIGN_SHIFT_R_HPP__

