#include <variables/const_declaration.hpp>
#include <string>

using namespace jawe;

ConstDeclaration::ConstDeclaration(Expr* expr)
	: Declaration(expr, QConst, TConstDeclaration)
{}

void ConstDeclaration::print(std::ostream& out) const
{
	out << "const ";
	expr()->print(out);
	out << ";" << std::endl;
}

void ConstDeclaration::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "Declaration [const]" << std::endl;
	expr()->dump_ast(out, tabs+1);
}

ConstDeclaration* ConstDeclaration::copy()
{
	return new ConstDeclaration(expr()->copy());
}

