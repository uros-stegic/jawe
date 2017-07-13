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
	out << ";";
}

void ConstDeclaration::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "Declaration [const] " << memory_address() << std::endl;
	expr()->dump_ast(out, tabs+1);
}

ConstDeclaration* ConstDeclaration::copy()
{
	auto ex = expr()->copy();
	auto result = new ConstDeclaration(ex);
	ex->set_parent(result);
	return result;
}

