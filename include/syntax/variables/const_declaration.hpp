#ifndef __CONST_DECLARATION_HPP__
#define __CONST_DECLARATION_HPP__

#include <variables/declaration.hpp>

namespace jawe {
class ConstDeclaration : public Declaration {
public:
	ConstDeclaration(Expr*);

	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	ConstDeclaration* copy() override;
};
}

#endif // __CONST_DECLARATION_HPP__

