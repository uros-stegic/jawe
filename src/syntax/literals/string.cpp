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

