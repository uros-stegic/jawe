#ifndef __ASSIGN_DIV_HPP__
#define __ASSIGN_DIV_HPP__

#include <operators/binary_operator.hpp>

namespace jawe {
class AssignDiv : public BinaryOperator {
public:
	AssignDiv(Expr*, Expr*);
};
}

#endif // __ASSIGN_DIV_HPP__

