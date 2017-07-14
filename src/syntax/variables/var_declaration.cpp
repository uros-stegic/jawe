#include <variables/var_declaration.hpp>

using namespace jawe;

VarDeclaration::VarDeclaration(Expr* expr)
	: Declaration(expr, QVar, TVarDeclaration)
{}

void VarDeclaration::print(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "var ";
	expr()->print(out, tabs+1);
	out << ";";
}

void VarDeclaration::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "Declaration [var] " << memory_address() << std::endl;
	expr()->dump_ast(out, tabs+1);
}

VarDeclaration* VarDeclaration::copy()
{
	auto ex = expr()->copy();
	auto result = new VarDeclaration(ex);
	ex->set_parent(result);
	return result;
}

