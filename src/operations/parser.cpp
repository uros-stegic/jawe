#include <operations/parser.hpp>
#include <utils/control.hpp>
#include <iostream>
#include <syntax.hpp>
#include <lang.syn.hpp>

using namespace jawe;

extern Ast* program;

void Parser::run() const
{
	yyparse();

	if( Control::get().dump_ast() ) {
		program->dump_ast(std::cout);
	}
	if( Control::get().dump_program() ) {
		program->print(std::cout);
	}
}
