#ifndef __TYPEOF_HPP__
#define __TYPEOF_HPP__

#include <operators/unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class TypeOf : public UnaryOperator {
public:
	TypeOf(Expr*);
};
}

#endif // __TYPEOF_HPP__

