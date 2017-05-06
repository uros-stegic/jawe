#ifndef __OPERATOR_HPP__
#define __OPERATOR_HPP__

#include <expr.hpp>

namespace jawe {
class Operator : public Expr {
public:
	Operator(std::string, const Priority&);
	std::string symbol() const;
	virtual void dump_ast(std::ostream&, int = 0) const override;

private:
	std::string m_symbol;
};
}

#endif // __OPERATOR_HPP__

