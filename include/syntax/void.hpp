#ifndef __VOID_HPP__
#define __VOID_HPP__

#include <unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class Void : public UnaryOperator {
public:
	Void(Expr*);
	void print(std::ostream&) const override;
};
}

#endif // __VOID_HPP__

