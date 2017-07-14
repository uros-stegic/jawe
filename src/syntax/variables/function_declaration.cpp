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

void FunctionDeclaration::print(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "function " << m_name << "(";
	m_function->print_args(out);
	out << ") ";
	m_function->body()->print(out, tabs+1);
	out << std::endl;
}

void FunctionDeclaration::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ')
		<< "FunctionDeclaration [" << m_name << "] " << memory_address()
		<< std::endl;

	m_function->dump_ast(out, tabs+1);
}

FunctionDeclaration* FunctionDeclaration::copy()
{
	auto fn = m_function->copy();
	auto result = new FunctionDeclaration(m_name, fn);
	fn->set_parent(result);
	return result;
}

Command* FunctionDeclaration::get_body()
{
	return m_function->get_body();
}

