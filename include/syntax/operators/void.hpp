#ifndef __VOID_HPP__
#define __VOID_HPP__

#include <operators/unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class Void : public UnaryOperator {
public:
	Void(Expr*);
};
}

#endif // __VOID_HPP__

