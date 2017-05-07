#ifndef __ASSIGN_BIT_XOR_HPP__
#define __ASSIGN_BIT_XOR_HPP__

#include <operators/binary_operator.hpp>
#include <variables/variable.hpp>

namespace jawe {
class AssignBitXor : public BinaryOperator {
public:
	AssignBitXor(Variable*, Expr*);
};
}

#endif // __ASSIGN_BIT_XOR_HPP__

