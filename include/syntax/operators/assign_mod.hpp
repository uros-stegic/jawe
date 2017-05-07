#ifndef __ASSIGN_MOD_HPP__
#define __ASSIGN_MOD_HPP__

#include <operators/binary_operator.hpp>
#include <variables/variable.hpp>

namespace jawe {
class AssignMod : public BinaryOperator {
public:
	AssignMod(Variable*, Expr*);
};
}

#endif // __ASSIGN_MOD_HPP__

