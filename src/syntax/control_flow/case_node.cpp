#include <control_flow/case_node.hpp>

using namespace jawe;

case_node::case_node(const shared_node& p, const shared_node& command)
	: basic_node("case")
	, m_case(p)
	, m_body(command)
{}


shared_node case_node::get_body() const {
	return m_body;
}

shared_node case_node::get_case() const {
	return m_case;
}
