#ifndef __ARRAY_ACCESS_HPP__
#define __ARRAY_ACCESS_HPP__

#include <operators/binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class ArrayAccess : public BinaryOperator {
public:
	ArrayAccess(Expr*, Expr*);
	void print(std::ostream&) const override;
};
}

#endif // __ARRAY_ACCESS_HPP__

