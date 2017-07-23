#include <shared_node.hpp>

using namespace jawe;


basic_node::basic_node(std::string symbol)
	:m_symbol(symbol)
{}

std::string basic_node::get_symbol() const {
	return m_symbol;
}
