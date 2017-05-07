#ifndef __DECLARATION_HPP__
#define __DECLARATION_HPP__

#include <command.hpp>
#include <expr.hpp>

namespace jawe {
enum Qualifier { QVar, QLet, QConst };
class Declaration : public Command {
public:
	Declaration(Expr*, Qualifier);
	~Declaration();
	Qualifier qualifier() const;
	Expr* expr() const;

private:
	Expr* m_expr;
	Qualifier m_qualifier;
};
}

#endif // __DECLARATION_HPP__

