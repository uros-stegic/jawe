#ifndef __RETURN_HPP__
#define __RETURN_HPP__

#include <command.hpp>
#include <expr.hpp>

namespace jawe {
class Return : public Command {
public:
	Return(Expr*);
	~Return();
	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	Return* copy() override;

private:
	Expr* m_expr;
};
}

#endif // __RETURN_HPP__

