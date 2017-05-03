#ifndef __LOGIC_AND_HPP__
#define __LOGIC_AND_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class LogicAnd : public BinaryOperator {
public:
	LogicAnd(Expr*, Expr*);
};
}

#endif // __LOGIC_AND_HPP__

