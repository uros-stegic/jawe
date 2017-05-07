#ifndef __ASSIGN_BIT_DIS_HPP__
#define __ASSIGN_BIT_DIS_HPP__

#include <operators/binary_operator.hpp>
#include <variables/variable.hpp>

namespace jawe {
class AssignBitDis : public BinaryOperator {
public:
	AssignBitDis(Variable*, Expr*);
};
}

#endif // __ASSIGN_BIT_DIS_HPP__

