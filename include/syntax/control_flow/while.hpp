#ifndef __WHILE_HPP__
#define __WHILE_HPP__

#include <command.hpp>
#include <expr.hpp>

namespace jawe {
class While : public Command {
public:
	While(Expr*,Command*);
	~While();
	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	Expr* get_expr() const;
	Command* get_body() const;

	While* copy() override;

private:
	Expr* m_cond;
	Command *m_body;
};
}

#endif // __WHILE_HPP__

