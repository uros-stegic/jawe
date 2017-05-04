#ifndef __FOR_HPP__
#define __FOR_HPP__

#include <command.hpp>
#include <expr.hpp>

namespace jawe {
class For : public Command {
public:
	For(Command*,Expr*,Command*,Command*);
	~For();
	void print(std::ostream&) const override;

private:
	Expr* m_cond;
	Command *m_init, *m_post, *m_body;
};
}

#endif // __FOR_HPP__

