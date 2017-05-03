#ifndef __NEW_HPP__
#define __NEW_HPP__

#include <unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class New : public UnaryOperator {
public:
	New(Expr*);
	void print(std::ostream&) const override;
};
}

#endif // __NEW_HPP__

