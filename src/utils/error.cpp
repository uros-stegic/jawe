#include <iostream>
#include <cstdlib>
#include <utils/error.hpp>
#include <utils/control.hpp>
#include <utils/reader.hpp>

using namespace jawe;

void Error::print(const std::string& msg)
{
	std::string filename = Control::get().input_filename();
	int line = Reader::get_reader().get_line();
	int position = Reader::get_reader().get_position();
	
	std::cerr	<< "[ERROR] "
				<< filename
				<< ":" << line
				<< ":" << position 
				<< ": " << msg
				<< std::endl;

	print_line(filename, line, position);
	std::exit(EXIT_FAILURE);
}

void Error::print_line(const std::string& filename, int line, int position)
{
	std::string buff = Reader::get_reader().get_buffer();
	std::cerr	<< std::string(2, ' ')
				<< buff << std::endl
				<< std::string(2, ' ') << std::string(position, ' ')
				<< "^" << std::endl;
}

