#ifndef __PRINTER__HPP__
#define __PRINTER__HPP__

#include <operations/basic_operation.hpp>

namespace jawe {
class Printer : public basic_operation {
public:
	void run() const;
};
}

#endif // __PRINTER__HPP__

