#ifndef __ASSIGN_BIT_CON_HPP__
#define __ASSIGN_BIT_CON_HPP__

#include <operators/binary_operator.hpp>
#include <variables/variable.hpp>

namespace jawe {
class AssignBitCon : public BinaryOperator {
public:
	AssignBitCon(Variable*, Expr*);
};
}

#endif // __ASSIGN_BIT_CON_HPP__

