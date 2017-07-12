#ifndef __BINARY_OPERATOR_HPP__
#define __BINARY_OPERATOR_HPP__

#include <string>
#include <iostream>

#include <expr.hpp>
#include <operators/operator.hpp>

namespace jawe {
class BinaryOperator : public Operator {
public:
	BinaryOperator(Expr*, Expr*, std::string, const Priority&);
	~BinaryOperator();
	void print(std::ostream& out) const override;
	void dump_ast(std::ostream& out, int = 0) const override;
	Expr* left() const;
	Expr* right() const;

	BinaryOperator* copy() override;

private:
	Expr *m_left, *m_right;
};
}

#endif // __BINARY_OPERATOR_HPP__

