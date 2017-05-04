#ifndef __UPLUS_HPP__
#define __UPLUS_HPP__

#include <operators/unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class UPlus : public UnaryOperator {
public:
	UPlus(Expr*);
};
}

#endif // __UPLUS_HPP__

