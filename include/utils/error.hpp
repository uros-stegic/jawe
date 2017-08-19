#ifndef __ERROR_HPP__
#define __ERROR_HPP__

#include <string>

namespace jawe {
class error {
public:
	static void print(const std::string&);

private:
	static void print_line(const std::string&, int, int);
};
}

#endif // __ERROR_HPP__
