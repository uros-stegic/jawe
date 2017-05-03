#ifndef __LOGIC_NOT_HPP__
#define __LOGIC_NOT_HPP__

#include <unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class LogicNot : public UnaryOperator {
public:
	LogicNot(Expr*);
};
}

#endif // __LOGIC_NOT_HPP__

