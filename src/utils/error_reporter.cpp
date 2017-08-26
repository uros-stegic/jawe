#include <iostream>
#include <cstdlib>

#include <boost/algorithm/string.hpp>

#include <syntax.hpp>
#include <utils/error_reporter.hpp>
#include <utils/control.hpp>
#include <utils/reader.hpp>

using namespace jawe;

void error_reporter::error(const std::string& msg, int line, int position)
{
	std::string filename = control::get().input_filename();

	std::cerr	<< "[ERROR] "
				<< filename
				<< ":" << line
				<< ":" << position
				<< ": " << msg
				<< std::endl;

	print_line(filename, line, position);
	std::exit(EXIT_FAILURE);
}

void error_reporter::error(const std::string& msg)
{
	int line = reader::get_reader().get_line();
	int position = reader::get_reader().get_position();

	error(msg, line, position);
}

void error_reporter::error(const std::string& msg, const shared_node& root)
{
	std::visit(lambda_composer{
		[msg](basic_node* node) {
			error_reporter::error(msg, node->get_row(), node->get_column());
		}
	}, *root);
}

void error_reporter::print_line(const std::string& filename, int line, int position)
{
	std::string buff = reader::get_reader().get_line(line-1);
	int old_len = buff.size();
	boost::trim(buff);
	int new_len = buff.size();
	std::cerr	<< std::string(4, ' ')
				<< buff << std::endl
				<< std::string(4 + position - 3 - (old_len - new_len), ' ')
				<< "~~^~~" << std::endl;
}
