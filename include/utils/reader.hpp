#ifndef __READER_HPP__
#define __READER_HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace jawe {

class reader {
public:
	~reader();

	reader(const reader&) = delete;
	reader(const reader&&) = delete;
	reader& operator=(const reader&) = delete;
	reader& operator=(reader&&) = delete;

	static reader& get_reader();
	std::string get_line(int) const;
	int get_line() const;
	int get_position() const;
	std::string get_buffer() const;

	/**
	 * Reads next character from input and puts it into buffer[0]
	 * @returns 0 if there are no more characters in input.
	 */
	int read(char*);

private:
	int m_current_line;
	int m_current_char;
	std::ifstream m_input;
	std::string m_internal_buffer;
	std::vector<std::string> m_archive;

	reader(std::string);

	char pop_char();
};
}

#endif // __READER_HPP__
