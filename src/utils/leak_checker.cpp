#include <utils/leak_checker.hpp>
#include <iostream>
#include <syntax.hpp>

using namespace jawe;

void leak_previewer::show_leaked(basic_node* cmd, std::ostream& out) {
	auto begin = cmd->begin();
	auto end = cmd->end();
	if( cmd->get() == 0 ) {
 		out << "No leaking detected" << std::endl;
 		return;
 	}
 	out << "Leaked ptrs: <" << std::endl;
 	for(;begin != end; begin++) {
 		auto command = static_cast<basic_node*>(*begin);
 		out << "    " << command << std::endl;
 	}
 	out << ">" << std::endl;
}

