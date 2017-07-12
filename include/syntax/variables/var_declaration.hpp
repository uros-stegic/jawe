#ifndef __VAR_DECLARATION_HPP__
#define __VAR_DECLARATION_HPP__

#include <variables/declaration.hpp>

namespace jawe {
class VarDeclaration : public Declaration {
public:
	VarDeclaration(Expr*);

	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	VarDeclaration* copy() override;
};
}

#endif // __VAR_DECLARATION_HPP__

