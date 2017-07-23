#include <variables/var_declaration_node.hpp>

using namespace jawe;

var_declaration_node::var_declaration_node(const shared_node& shared_n)
	: declaration_node(shared_n, QVar, "var")
{}
