#include <variables/const_declaration_node.hpp>
#include <string>

using namespace jawe;

const_declaration_node::const_declaration_node(const shared_node &shared_n)
	: declaration_node(shared_n, QConst, "const")
{}

