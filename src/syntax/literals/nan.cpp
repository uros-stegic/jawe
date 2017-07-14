#include <literals/nan.hpp>

using namespace jawe;

Nan::Nan()
{}

Nan::~Nan()
{}

void Nan::print(std::ostream& out, int tabs) const
{
	out << "nan";
}

void Nan::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ') << "NaN " << memory_address() << std::endl;
}

Nan* Nan::copy()
{
	return new Nan();
}

