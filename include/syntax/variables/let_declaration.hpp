#ifndef __LET_DECLARATION_HPP__
#define __LET_DECLARATION_HPP__

#include <variables/declaration.hpp>

namespace jawe {
class LetDeclaration : public Declaration {
public:
	LetDeclaration(Expr*);

	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	LetDeclaration* copy() override;
};
}

#endif // __LET_DECLARATION_HPP__

