#ifndef __DIVIDE_HPP__
#define __DIVIDE_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class Divide : public BinaryOperator {
public:
	Divide(Expr*, Expr*);
};
}

#endif // __DIVIDE_HPP__

