#ifndef __ASSIGN_POW_HPP__
#define __ASSIGN_POW_HPP__

#include <operators/binary_operator.hpp>

namespace jawe {
class AssignPow : public BinaryOperator {
public:
	AssignPow(Expr*, Expr*);
};
}

#endif // __ASSIGN_POW_HPP__

