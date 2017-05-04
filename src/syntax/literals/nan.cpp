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

