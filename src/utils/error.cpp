#include <iostream>
#include <cstdlib>
#include <utils/error.hpp>
#include <utils/control.hpp>
#include <utils/reader.hpp>

using namespace jawe;

void error::print(const std::string& msg)
{
	std::string filename = control::get().input_filename();
	int line = reader::get_reader().get_line();
	int position = reader::get_reader().get_position();

	std::cerr	<< "[ERROR] "
				<< filename
				<< ":" << line
				<< ":" << position
				<< ": " << msg
				<< std::endl;

	print_line(filename, line, position);
	std::exit(EXIT_FAILURE);
}

void error::print_line(const std::string& filename, int line, int position)
{
	std::string buff = reader::get_reader().get_buffer();
	std::cerr	<< std::string(2, ' ')
				<< buff << std::endl
				<< std::string(2, ' ') << std::string(position, ' ')
				<< "^" << std::endl;
}
