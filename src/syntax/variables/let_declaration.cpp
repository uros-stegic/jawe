#include <variables/let_declaration.hpp>

using namespace jawe;

LetDeclaration::LetDeclaration(Expr* expr)
	: Declaration(expr, QLet)
{}

void LetDeclaration::print(std::ostream& out) const
{
	out << "let ";
	expr()->print(out);
	out << ";" << std::endl;
}

void LetDeclaration::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "Declaration [let]" << std::endl;
	expr()->dump_ast(out, tabs+1);
}

