#include <iostream>
#include <string>
#include <config.h>
#include <control.hpp>
#include <syntax.hpp>
#include <lang.syn.hpp>
#include <cstdio>
#include <cstdlib>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_functions.hpp>

using namespace jawe;
namespace bpo = boost::program_options;

Control::Control(int argc, char **argv)
	: m_argc(argc)
	, m_argv(argv)
	, m_desc("Usage: jawe [OPTION]... --input-file program.js")
{
	m_desc.add_options()
		("help,h", "prints this help message")
		("version,v", "prints version info")
		("verbose", "prints verbose parsing information")
		("dump-ast", "prints parsed abstract syntax tree")
		("input-file", bpo::value<std::string>(&m_input), "input filename")
		("output-file", bpo::value<std::string>(&m_output)->default_value("a.out"), "output filename")
	;
	bpo::store(bpo::parse_command_line(argc, argv, m_desc), m_vars);
	bpo::notify(m_vars);
}

extern int yydebug;
extern FILE* yyin;
extern Ast* program;
void Control::run() const
{
	if( m_vars.count("verbose") ) {
		yydebug = 1;
	}
	if( m_vars.count("help") ) {
		m_print_help();
		return;
	}
	else if( m_vars.count("version") ) {
		m_print_version();
		return;
	}
	else if( m_vars.count("input-file") ) {
		yyin = std::fopen(m_input.c_str(), "r");
		if( !yyin ) {
			std::cerr << "Cannot open file: " << m_input << std::endl;
			std::exit(EXIT_FAILURE);
		}
		yyparse();
		if( m_vars.count("dump-ast") ) {
			program->dump_ast(std::cout);
		}
		else {
			program->print(std::cout);
		}
		std::fclose(yyin);
	}
	else {
		std::cerr << "jawe: no input file." << std::endl;
		std::cerr << "Try: 'jawe --help' for more information." << std::endl;
	}
}

void Control::m_print_help() const
{
	std::cout << m_desc << std::endl;
}
void Control::m_print_version() const
{
	std::cout	<< "jawe "
				<< jawe_VERSION_MAJOR
				<< "."
				<< jawe_VERSION_MINOR
				<< std::endl;
	std::cout << "License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>." << std::endl;
	std::cout << "This is free software: you are free to change and redistribute it." << std::endl;
	std::cout << "There is NO WARRANTY, to the extent permitted by law." << std::endl << std::endl;
	std::cout << "Source code available at <https://github.com/uros-stegic/jawe>" << std::endl;
	std::cout << "Written by Uros Stegic" << std::endl;
}

