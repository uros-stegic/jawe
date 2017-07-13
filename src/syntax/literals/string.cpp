#include <literals/string.hpp>

using namespace jawe;

String::String(std::string str)
	: m_string(str)
{}

String::~String()
{}

void String::print(std::ostream& out) const
{
	out << '"' << m_string << '"';
}

void String::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ')
		<< "String [\"" << m_string << "\"] [" << this << ": from <" << get_parent() << ">]" << std::endl;
}

String* String::copy()
{
	return new String(m_string);
}

