#include <operations/printer.hpp>
#include <utils/control.hpp>
#include <iostream>
#include <command.hpp>

using namespace jawe;

extern Command* program;

void Printer::run() const
{
	if( Control::get().dump_ast() ) {
		program->dump_ast(std::cout);
	}
	if( Control::get().dump_program() ) {
		program->print(std::cout);
	}
}
