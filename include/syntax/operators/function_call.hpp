#ifndef __FUNCTION_CALL_HPP__
#define __FUNCTION_CALL_HPP__

#include <expr.hpp>
#include <vector>

namespace jawe {
class FunctionCall : public Expr {
public:
	FunctionCall(Expr*);
	FunctionCall(Expr*,const std::vector<Expr*>&);
	~FunctionCall();

	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	void insert(Expr*);
	FunctionCall* copy() override;

private:
	Expr* m_expr;
	std::vector<Expr*> m_args;

	void print_args(std::ostream&) const;
	void dump_args(std::ostream&, int = 0) const;
};
}

#endif // __FUNCTION_CALL_HPP__

