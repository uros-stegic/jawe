#ifndef __TERNARY_OPERATOR_HPP__
#define __TERNARY_OPERATOR_HPP__

#include <operators/operator.hpp>
#include <expr.hpp>

namespace jawe {
class TernaryOperator : public Operator {
public:
	TernaryOperator(Expr*, Expr*, Expr*, std::string, std::string, const Priority&);
	~TernaryOperator();

	void print(std::ostream&) const override;
	Expr* first_operand() const;
	Expr* second_operand() const;
	Expr* third_operand() const;

private:
	Expr *m_first, *m_second, *m_third;
	std::string m_symbol2;
};
}
#endif // __TERNARY_OPERATOR_HPP__

