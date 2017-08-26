#ifndef __ERROR_REPORTER_HPP__
#define __ERROR_REPORTER_HPP__

#include <string>
#include <shared_node.hpp>

namespace jawe {
class error_reporter {
public:
	static void error(const std::string&);
	static void error(const std::string&, int, int);
	static void error(const std::string&, const shared_node&);

private:
	static void print_line(const std::string&, int, int);
};
}

#endif // __ERROR_REPORTER_HPP__

