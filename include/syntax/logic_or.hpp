#ifndef __LOGIC_OR_HPP__
#define __LOGIC_OR_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class LogicOr : public BinaryOperator {
public:
	LogicOr(Expr*, Expr*);
};
}

#endif // __LOGIC_OR_HPP__

