#include <literals/object_node.hpp>
#include <shared_node.hpp>
#include <algorithm>
#include <utility>

using namespace jawe;

object_node::object_node()
	: abstract_object_node("object")
{}

object_node::object_node(const std::map<std::string, shared_node>& pairs)
	: abstract_object_node("object")
	, m_pairs(pairs)
{}

void object_node::set(std::string name, shared_node expr)
{
	m_pairs[name] = expr;
}

std::map<std::string, shared_node> object_node::get_pairs()
{
	return m_pairs;
}
