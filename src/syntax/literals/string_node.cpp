#include <literals/string_node.hpp>

using namespace jawe;

string_node::string_node(std::string str)
	:primitive_node(str)
	 ,m_string(str)
{}

