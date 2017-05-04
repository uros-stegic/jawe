#ifndef __DOT_ACCESS_HPP__
#define __DOT_ACCESS_HPP__

#include <operators/binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class DotAccess : public BinaryOperator {
public:
	DotAccess(Expr*, Expr*);
	void print(std::ostream&) const override;
};
}

#endif // __DOT_ACCESS_HPP__

