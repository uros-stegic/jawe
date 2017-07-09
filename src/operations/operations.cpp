#include <operations/operations.hpp>
#include <fstream>
#include <string>
#include <cstdlib>
#include <syntax.hpp>
#include <lang.syn.hpp>
#include <utils/control.hpp>

using namespace jawe;

extern Ast* program;

void Operations::begin_compilation()
{
	assert_file();

	yyparse();

	if( Control::get().dump_ast() ) {
		program->dump_ast(std::cout);
	}
	if( Control::get().dump_program() ) {
		program->print(std::cout);
	}
}

void Operations::assert_file()
{
	std::string input = Control::get().input_filename();
	std::ifstream test_input(input);
	if( !test_input ) {
		std::cerr << "jawe: Cannot open input file " << input << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

