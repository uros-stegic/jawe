#ifndef __RETURN_HPP__
#define __RETURN_HPP__

#include <command.hpp>
#include <expr.hpp>

namespace jawe {
class Return : public Command {
public:
	Return(Expr*);
	~Return();
	void print(std::ostream&) const override;

private:
	Expr* m_expr;
};
}

#endif // __RETURN_HPP__
