#ifndef __ASSIGN_MOD_HPP__
#define __ASSIGN_MOD_HPP__

#include <operators/binary_operator.hpp>

namespace jawe {
class AssignMod : public BinaryOperator {
public:
	AssignMod(Expr*, Expr*);
};
}

#endif // __ASSIGN_MOD_HPP__

