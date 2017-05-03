#ifndef __UNARY_OPERATOR_HPP__
#define __UNARY_OPERATOR_HPP__

#include <operator.hpp>
#include <expr.hpp>
#include <iostream>

namespace jawe {
class UnaryOperator : public Operator {
public:
	UnaryOperator(Expr*, std::string, const Priority&);
	~UnaryOperator();

	void print(std::ostream&) const override;
	Expr* operand() const;

private:
	Expr* m_operand;
};
}

#endif // __UNARY_OPERATOR_HPP__

