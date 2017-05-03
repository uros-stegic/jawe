#ifndef __EQUALS_HPP__
#define __EQUALS_HPP__

#include <binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class Equals : public BinaryOperator {
public:
	Equals(Expr*, Expr*);
};
}

#endif // __EQUALS_HPP__

