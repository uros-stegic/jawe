#include <variables/let_declaration_node.hpp>

using namespace jawe;

let_declaration_node::let_declaration_node(const shared_node& shared_n)
	: declaration_node(shared_n, QLet, "let")
{}

