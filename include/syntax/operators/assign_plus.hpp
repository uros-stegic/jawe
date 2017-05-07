#ifndef __ASSIGN_PLUS_HPP__
#define __ASSIGN_PLUS_HPP__

#include <operators/binary_operator.hpp>

namespace jawe {
class AssignPlus : public BinaryOperator {
public:
	AssignPlus(Expr*, Expr*);
};
}

#endif // __ASSIGN_PLUS_HPP__

