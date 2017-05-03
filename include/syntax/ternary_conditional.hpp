#ifndef __TERNARY_CONDITIONAL_HPP__
#define __TERNARY_CONDITIONAL_HPP__

#include <ternary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class TernaryConditional : public TernaryOperator {
public:
	TernaryConditional(Expr*, Expr*, Expr*);
};
}

#endif // __TERNARY_CONDITIONAL_HPP__

