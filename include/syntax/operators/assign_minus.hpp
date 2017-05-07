#ifndef __ASSIGN_MINUS_HPP__
#define __ASSIGN_MINUS_HPP__

#include <operators/binary_operator.hpp>

namespace jawe {
class AssignMinus : public BinaryOperator {
public:
	AssignMinus(Expr*, Expr*);
};
}

#endif // __ASSIGN_MINUS_HPP__

