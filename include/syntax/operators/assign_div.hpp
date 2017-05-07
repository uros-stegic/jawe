#ifndef __ASSIGN_DIV_HPP__
#define __ASSIGN_DIV_HPP__

#include <operators/binary_operator.hpp>
#include <variables/variable.hpp>

namespace jawe {
class AssignDiv : public BinaryOperator {
public:
	AssignDiv(Variable*, Expr*);
};
}

#endif // __ASSIGN_DIV_HPP__

