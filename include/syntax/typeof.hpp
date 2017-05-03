#ifndef __TYPEOF_HPP__
#define __TYPEOF_HPP__

#include <unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class TypeOf : public UnaryOperator {
public:
	TypeOf(Expr*);
	void print(std::ostream&) const override;
};
}

#endif // __TYPEOF_HPP__

