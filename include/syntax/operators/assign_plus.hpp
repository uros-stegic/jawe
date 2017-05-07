#ifndef __ASSIGN_PLUS_HPP__
#define __ASSIGN_PLUS_HPP__

#include <operators/binary_operator.hpp>
#include <variables/variable.hpp>

namespace jawe {
class AssignPlus : public BinaryOperator {
public:
	AssignPlus(Variable*, Expr*);
};
}

#endif // __ASSIGN_PLUS_HPP__

