#include <variables/variable_node.hpp>

using namespace jawe;

variable_node::variable_node(std::string name)
	:expr_node(name)
	, m_name(name)
{}

