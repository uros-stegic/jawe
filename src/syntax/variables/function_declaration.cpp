#include <variables/function_declaration.hpp>

using namespace jawe;

FunctionDeclaration::FunctionDeclaration(std::string name, Function* function)
	: Command(TFunctionDeclaration)
	, m_name(name)
	, m_function(function)
{}

FunctionDeclaration::~FunctionDeclaration()
{
	delete m_function;
}

void FunctionDeclaration::print(std::ostream& out) const
{
	out << "function " << m_name << "(";
	m_function->print_args(out);
	out << ") {" << std::endl;
	m_function->body()->print(out);
	out << "}" << std::endl;
}

void FunctionDeclaration::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ')
		<< "FunctionDeclaration [" << m_name << "]"
		<< std::endl;

	m_function->dump_ast(out, tabs+1);
}

FunctionDeclaration* FunctionDeclaration::copy()
{
	return new FunctionDeclaration(m_name, m_function->copy());
}

