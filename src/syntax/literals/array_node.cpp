#include <literals/array_node.hpp>
#include <algorithm>

using namespace jawe;

array_node::array_node()
	: abstract_object_node("array_node")
{}

array_node::array_node(const std::vector<shared_node>& elements)
	: abstract_object_node("array_node")
	, m_elements(elements)
{}

void array_node::push_back(const shared_node& expr)
{
	m_elements.push_back(expr);
}

std::vector<shared_node> array_node::get_elements()
{
	return m_elements;
}
