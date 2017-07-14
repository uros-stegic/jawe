#include <operations/printer.hpp>
#include <utils/control.hpp>
#include <iostream>
#include <command.hpp>

using namespace jawe;

extern Command* program;

void Printer::run() const
{
	if( Control::get().dump_ast() ) {
		std::cout	<< "~~~~~ Previewing syntax tree"
					<< std::endl << std::endl;
		program->dump_ast(std::cout);
		std::cout	<< std::endl
					<< "~~~~~ Finished syntax tree"
					<< std::endl << std::endl;
	}
	if( Control::get().dump_program() ) {
		std::cout	<< "~~~~~ Printing program"
					<< std::endl << std::endl;
		program->print(std::cout);
		std::cout	<< std::endl
					<< "~~~~~ Finished printing"
					<< std::endl << std::endl;
	}
}
