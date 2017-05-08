#ifndef __INSTANCE_OF_HPP__
#define __INSTANCE_OF_HPP__

#include <operators/binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class InstanceOf : public BinaryOperator {
public:
	InstanceOf(Expr*, Expr*);
};
}

#endif // __INSTANCE_OF_HPP__

