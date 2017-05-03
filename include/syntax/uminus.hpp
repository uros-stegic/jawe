#ifndef __UMINUS_HPP__
#define __UMINUS_HPP__

#include <unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class UMinus : public UnaryOperator {
public:
	UMinus(Expr*);
};
}

#endif // __UMINUS_HPP__

