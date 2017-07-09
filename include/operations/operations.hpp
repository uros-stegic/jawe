#ifndef __OPERATIONS_HPP__
#define __OPERATIONS_HPP__

#include <string>

namespace jawe {
class Operations {
public:
	Operations() = delete;
	Operations(const Operations&) = delete;
	void operator=(const Operations&) = delete;

	static void begin_compilation();

private:
	static void assert_file();
};
}

#endif // __OPERATIONS_HPP__

