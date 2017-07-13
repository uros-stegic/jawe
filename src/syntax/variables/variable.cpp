#include <variables/variable.hpp>

using namespace jawe;

Variable::Variable(std::string name)
	: Expr(TVariable)
	, m_name(name)
{}

Variable::~Variable()
{}

void Variable::print(std::ostream& out) const
{
	out << m_name;
}

void Variable::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ')
		<< "Variable [" << m_name << "] " << memory_address() << std::endl;
}

Variable* Variable::copy()
{
	return new Variable(m_name);
}

