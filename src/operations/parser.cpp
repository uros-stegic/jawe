#include <operations/parser.hpp>
#include <syntax.hpp>
#include <lang.syn.hpp>

using namespace jawe;

void Parser::run() const
{
	yyparse();
}
