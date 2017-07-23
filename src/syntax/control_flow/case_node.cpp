#include <control_flow/case_node.hpp>

using namespace jawe;

case_node::case_node(const primitive_node& p, const shared_node& command)
	: basic_node("case")
	, m_case(p)
	, m_command(command)
{}

