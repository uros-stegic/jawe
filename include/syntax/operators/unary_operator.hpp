#ifndef __UNARY_OPERATOR_HPP__
#define __UNARY_OPERATOR_HPP__

#include <operators/operator.hpp>
#include <expr.hpp>
#include <iostream>

namespace jawe {
class UnaryOperator : public Operator {
public:
	UnaryOperator(Expr*, std::string, const Priority&);
	~UnaryOperator();

	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream& out, int = 0) const override;
	Expr* operand() const;

	UnaryOperator* copy() override;

private:
	Expr* m_operand;
};
}

#endif // __UNARY_OPERATOR_HPP__

