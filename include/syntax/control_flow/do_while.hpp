#ifndef __DO_WHILE_HPP__
#define __DO_WHILE_HPP__

#include <command.hpp>
#include <expr.hpp>

namespace jawe {
class DoWhile : public Command {
public:
	DoWhile(Command*,Expr*);
	~DoWhile();
	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;

private:
	Command *m_body;
	Expr* m_cond;
};
}

#endif // __DO_WHILE_HPP__

