#include <utils/leak_checker.hpp>
#include <iostream>
#include <syntax.hpp>

using namespace jawe;

void LeakPreviewer::show_leaked(Command* cmd, std::ostream& out) {
	auto begin = cmd->begin();
	auto end = cmd->end();
	if( cmd->get() == 0 ) {
		out << "No leaking detected" << std::endl;
		return;
	}
	out << "Leaked ptrs: <" << std::endl;
	for(;begin != end; begin++) {
		auto command = static_cast<Command*>(*begin);
		out << "    " << command;
		out << " [" << command->get_type();
		if( command->get_type() == TExpr ) {
			out << ": " << static_cast<Expr*>(command)->priority();
		}
		out << "]" << std::endl;
	}
	out << ">" << std::endl;
}

