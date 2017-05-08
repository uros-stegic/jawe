#include <literals/function.hpp>
#include <algorithm>

using namespace jawe;

Function::Function(std::vector<std::string> args, Command* body)
	: m_args(args)
	, m_body(body)
{}

Function::~Function()
{
	delete m_body;
}

Command* Function::body() const
{
	return m_body;
}

void Function::print(std::ostream& out) const
{
	out << "function (";
	print_args(out);
	out << ") {" << std::endl;
	m_body->print(out);
	out << "}" << std::endl;
}

void Function::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "Function [";
	print_args(out);
	out << "]" << std::endl;
	m_body->dump_ast(out, tabs+1);
}

void Function::print_args(std::ostream& out) const
{
	if( m_args.size() == 0 ) {
		return;
	}
	out << *std::begin(m_args);
	std::for_each(
		++std::begin(m_args),
		std::end(m_args),
		[&](std::string arg) {
			out << ", " << arg;
		}
	);
}

