#ifndef __IN_HPP__
#define __IN_HPP__

#include <operators/binary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class In : public BinaryOperator {
public:
	In(Expr*, Expr*);
};
}

#endif // __IN_HPP__

