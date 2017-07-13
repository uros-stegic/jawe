#include <literals/primitive.hpp>

using namespace jawe;

Primitive::Primitive()
	: Literal(TPrimitive)
{}

void Primitive::dump_ast(std::ostream& out, int tabs) const
{
	out << std::string(4*tabs, ' ');
	out << "primitive [" << "]" << std::endl;
}

