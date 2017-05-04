#ifndef __MOD_HPP__
#define __MOD_HPP__

#include <operators/binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class Mod : public BinaryOperator {
public:
	Mod(Expr*, Expr*);
};
}

#endif // __MOD_HPP__

