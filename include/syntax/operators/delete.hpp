#ifndef __DELETE_HPP__
#define __DELETE_HPP__

#include <operators/unary_operator.hpp>
#include <expr.hpp>

namespace jawe {
class Delete : public UnaryOperator {
public:
	Delete(Expr*);
	void print(std::ostream&) const override;
};
}

#endif // __DELETE_HPP__

