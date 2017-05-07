#ifndef __SWITCH_HPP__
#define __SWITCH_HPP__

#include <command.hpp>
#include <expr.hpp>
#include <vector>

namespace jawe {
class Switch : public Command {
public:
	Switch(Expr*, const std::vector<Command*>&);
	~Switch();

	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;

private:
	Expr* m_expr;
	std::vector<Command*> m_cases;
};
}

#endif // __SWITCH_HPP__

