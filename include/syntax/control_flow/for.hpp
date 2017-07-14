#ifndef __FOR_HPP__
#define __FOR_HPP__

#include <command.hpp>
#include <expr.hpp>

namespace jawe {
class For : public Command {
public:
	For(Command*,Expr*,Command*,Command*);
	~For();
	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	Expr* get_expr() const;
	Command* get_body() const;
	Command* get_init() const;
	Command* get_post() const;

	For* copy() override;

private:
	Expr* m_cond;
	Command *m_init, *m_post, *m_body;
};
}

#endif // __FOR_HPP__

