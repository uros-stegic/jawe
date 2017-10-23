#ifndef __READER_HPP__
#define __READER_HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace jawe {

/** \brief Custom buffered file reader used for lexical analysis.
 *
 * Singleton class that is used in system FLEX that does the lexical analysis. It
 * keeps location information of the token read from input. FLEX's default reader
 * is replaced with this one by overriding YYLEX macro.
 * */
class reader {
public:
	~reader();

	/** Disables copy constructor to prevent copying a singleton instance. */
	reader(const reader&) = delete;

	/** Disables move constructor to prevent prevent moving a singleton instance. */

	reader(const reader&&) = delete;

	/** Disables copy assignment operator to prevent copying a singleton instance. */
	reader& operator=(const reader&) = delete;

	/** Disables move assignment operator to prevent moving a singleton instance. */
	reader& operator=(reader&&) = delete;

	/** Gets the singleton instance (creates it upon first call) */
	static reader& get_reader();

	/** 
	 * Gets specific line.
	 *
	 * @param line_no line number that user wants to fetch.
	 */
	std::string get_line(int line_no) const;

	/** Gets the line number of the line that is currently being read. */
	int get_line() const;

	/** Gets the column number from the line that is currently being read. */
	int get_position() const;

	/** Gets the content of the buffer. */
	std::string get_buffer() const;

	/**
	 * Reads next character from input and puts it into buffer[0].
	 *
	 * This function gets called in the YYLEX macro.
	 * @returns 0 if there are no more characters in input.
	 */
	int read(char*);

private:
	int m_current_line;
	int m_current_char;
	std::ifstream m_input;
	std::string m_internal_buffer;
	std::vector<std::string> m_archive;

	/**
	 * Cunstructs the reader object, and initializes input stream.
	 *
	 * @param filename absolute or relative path to the file that contains source.
	 */
	reader(std::string filename);

	/**
	 * Removes one character from the current bufer.
	 */
	char pop_char();
};
}

#endif // __READER_HPP__
