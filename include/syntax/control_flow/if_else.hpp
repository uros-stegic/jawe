#ifndef __IF_ELSE_HPP__
#define __IF_ELSE_HPP__

#include <command.hpp>
#include <expr.hpp>

namespace jawe {
class IfElse : public Command {
public:
	IfElse(Expr*,Command*,Command* = nullptr);
	~IfElse();
	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	Expr* get_expr() const;
	Command* get_if() const;
	Command* get_else() const;

	IfElse* copy() override;

private:
	Expr* m_expr;
	Command *m_if, *m_else;
};
}

#endif // __IF_ELSE_HPP__

