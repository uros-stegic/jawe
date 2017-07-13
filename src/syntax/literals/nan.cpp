#include <literals/nan.hpp>

using namespace jawe;

Nan::Nan()
{}

Nan::~Nan()
{}

void Nan::print(std::ostream& out) const
{
	out << "nan";
}

void Nan::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "NaN [" << this << ": from <" << get_parent() << ">]" << std::endl;
}

Nan* Nan::copy()
{
	return new Nan();
}

