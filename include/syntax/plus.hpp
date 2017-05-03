#ifndef __PLUS_HPP__
#define __PLUS_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class Plus : public BinaryOperator {
public:
	Plus(Expr*, Expr*);
};
}

#endif // __PLUS_HPP__

