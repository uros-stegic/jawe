#ifndef __ASSIGN_BIT_DIS_HPP__
#define __ASSIGN_BIT_DIS_HPP__

#include <operators/binary_operator.hpp>

namespace jawe {
class AssignBitDis : public BinaryOperator {
public:
	AssignBitDis(Expr*, Expr*);
};
}

#endif // __ASSIGN_BIT_DIS_HPP__

