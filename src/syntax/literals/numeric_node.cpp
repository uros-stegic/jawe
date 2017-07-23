#include <literals/numeric_node.hpp>
#include <string>

using namespace jawe;

numeric_node::numeric_node(double value)
	: primitive_node(std::to_string(value))
	  ,m_value(value)
{}

double numeric_node::get_value() const
{
	return m_value;
}


