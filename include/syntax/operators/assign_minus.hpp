#ifndef __ASSIGN_MINUS_HPP__
#define __ASSIGN_MINUS_HPP__

#include <operators/binary_operator.hpp>
#include <variables/variable.hpp>

namespace jawe {
class AssignMinus : public BinaryOperator {
public:
	AssignMinus(Variable*, Expr*);
};
}

#endif // __ASSIGN_MINUS_HPP__

