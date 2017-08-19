#ifndef __FILE_CHECKER__HPP__
#define __FILE_CHECKER__HPP__

#include <operations/basic_operation.hpp>

namespace jawe {
class file_checker : public basic_operation {
public:
	void run() const;
};
}

#endif // __FILE_CHECKER__HPP__
