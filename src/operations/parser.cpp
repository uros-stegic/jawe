#include <operations/parser.hpp>
#include <utils/control.hpp>
#include <iostream>
#include <syntax.hpp>
#include <lang.syn.hpp>

using namespace jawe;

extern Command* program;

void Parser::run() const
{
	yyparse();
}
