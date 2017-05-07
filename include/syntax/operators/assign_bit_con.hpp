#ifndef __ASSIGN_BIT_CON_HPP__
#define __ASSIGN_BIT_CON_HPP__

#include <operators/binary_operator.hpp>

namespace jawe {
class AssignBitCon : public BinaryOperator {
public:
	AssignBitCon(Expr*, Expr*);
};
}

#endif // __ASSIGN_BIT_CON_HPP__

