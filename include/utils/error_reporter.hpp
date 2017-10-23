#ifndef __ERROR_REPORTER_HPP__
#define __ERROR_REPORTER_HPP__

#include <string>
#include <shared_node.hpp>

namespace jawe {

/** \brief Class used as main error reporting system throughout the project.
 *
 * This class is can be used in all phases of compilation (parser, semantic analyzer...).
 */
class error_reporter {
public:
	/**
	 * Reports error message.
	 *
	 * This function should be used only in parsing phase since it will gather location information
	 * from the reader (it'll use lastly buffered state).
	 *
	 * @param msg message that is to be written to the user.
	 */
	static void error(const std::string& msg);

	/**
	 * Reports error message.
	 *
	 * This function is more safe to use for error reporting since programmer can explicitly tell
	 * on which row&column error occured.
	 *
	 * @param msg message that is to be written to the user.
	 * @param row_no row number in which error has occured.
	 * @param col_no column number in which error has occured.
	 */
	static void error(const std::string& msg, int row_no, int col_no);

	/**
	 *	Reports error message.
	 *
	 *	This function is probably most practical since it can read location information directly from the passed AST
	 *	node.
	 *
	 *	@param msg message that is to be written to the user.
	 *	@param node AST node which provoked the error (it should contain location info).
	 */
	static void error(const std::string& msg, const shared_node& node);

private:

	/**
	 * Prints the actual message.
	 *
	 * This method does the heavy lifting and contains hardcoded format for error reporting.
	 *
	 * @param msg message that is to be written to the user.
	 * @param row_no row number in which error has occured.
	 * @param col_no column number in which error has occured.
	 * 
	 * @see jawe::error_reporter::error()
	 */
	static void print_line(const std::string& msg, int row_no, int col_no);
};
}

#endif // __ERROR_REPORTER_HPP__

