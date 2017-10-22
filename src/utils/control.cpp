#include <iostream>
#include <fstream>
#include <string>
#include <config.h>
#include <utils/control.hpp>
#include <operations/operations.hpp>
#include <cstdlib>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_functions.hpp>

using namespace jawe;

extern int yydebug;

namespace bpo = boost::program_options;

control::control(int argc, char **argv)
	: m_argc(argc)
	, m_argv(argv)
	, m_desc("Usage: jawe [OPTION]... --input-file program.js")
	, m_context()
	, m_module(std::make_unique<llvm::Module>("main_module", m_context))
{
	m_desc.add_options()
		("help,h",		"prints this help message")
		("version,v",	"prints version info")
		("verbose",		"prints verbose parsing information")
		("dump-ast",	"prints parsed abstract syntax tree")
		("dump-ir",		"prints llvm IR code")
		("print",		"prints input program back to the output")
		("memory",		"shows memory addresses of AST nodes")
		("check-leaks",	"checks if any AST node failed to deallocate")
		("input-file",	bpo::value<std::string>(&m_input), "input filename")
		("output-file",	bpo::value<std::string>(&m_output)->default_value("a.out"), "output filename")
	;
	bpo::store(bpo::parse_command_line(argc, argv, m_desc), m_vars);
	bpo::notify(m_vars);

	yydebug = m_vars.count("verbose");
	m_dump_ast = m_vars.count("dump-ast");
	m_dump_ir = m_vars.count("dump-ir");
	m_dump_program = m_vars.count("print");
	m_show_memory = m_vars.count("memory");
	m_check_leaks = m_vars.count("check-leaks");
}

control& control::get(int argc, char** args)
{
	static control instance(argc, args);
	return instance;
}

void control::run() const
{
	if( m_vars.count("help") ) {
		m_print_help();
	}
	else if( m_vars.count("version") ) {
		m_print_version();
	}
	else if( m_vars.count("input-file") ) {
		operations::run_compilation<
			file_checker,
			parser,
		  empty_remover,
			optimizer<hoister>,
			semantic_analyzer<reference_checker, const_checker>,
			code_generator,
			printer
		>();
	}
	else {
		std::cerr << "jawe: no input file." << std::endl;
		std::cerr << "Try: 'jawe --help' for more information." << std::endl;
	}
}

void control::m_print_help() const
{
	std::cout << m_desc << std::endl;
}
void control::m_print_version() const
{
	std::cout	<< "jawe v"
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

std::string control::input_filename() const
{
	return m_input;
}
bool control::dump_ast() const
{
	return m_dump_ast;
}
bool control::dump_ir() const
{
	return m_dump_ir;
}
bool control::dump_program() const
{
	return m_dump_program;
}
bool control::show_memory() const
{
	return m_show_memory;
}
bool control::check_leaks() const
{
	return m_check_leaks;
}

llvm::LLVMContext& control::get_context()
{
	return m_context;
}
std::unique_ptr<llvm::Module>& control::get_module()
{
	return m_module;
}
