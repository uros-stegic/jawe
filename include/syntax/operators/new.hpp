#ifndef __NEW_HPP__
#define __NEW_HPP__

#include <operators/unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class New : public UnaryOperator {
public:
	New(Expr*);
};
}

#endif // __NEW_HPP__

