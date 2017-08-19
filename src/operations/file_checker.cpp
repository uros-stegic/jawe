#include <operations/file_checker.hpp>
#include <utils/control.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace jawe;

void file_checker::run() const
{
	std::string input = control::get().input_filename();
	std::ifstream test_input(input);
	if( !test_input ) {
		std::cerr << "jawe: Cannot open input file " << input << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
