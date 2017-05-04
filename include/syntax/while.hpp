#ifndef __WHILE_HPP__
#define __WHILE_HPP__

#include <command.hpp>
#include <expr.hpp>

namespace jawe {
class While : public Command {
public:
	While(Expr*,Command*);
	~While();
	void print(std::ostream&) const override;

private:
	Expr* m_cond;
	Command *m_body;
};
}

#endif // __WHILE_HPP__

