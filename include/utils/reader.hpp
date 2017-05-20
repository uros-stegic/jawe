#ifndef __READER_HPP__
#define __READER_HPP__

#include <fstream>
#include <iostream>
#include <string>

namespace jawe {

class Reader {
public:
	~Reader();

	Reader(const Reader&) = delete;
	Reader(const Reader&&) = delete;
	Reader& operator=(const Reader&) = delete;
	Reader& operator=(Reader&&) = delete;

	static Reader& get_reader();
	int get_line() const;
	int get_position() const;

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

	Reader(std::string);

	char pop_char();
};
}

#endif // __READER_HPP__

