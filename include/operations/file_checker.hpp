#ifndef __FILE_CHECKER__HPP__
#define __FILE_CHECKER__HPP__

#include <operations/basic_operation.hpp>

namespace jawe {
/** \brief Operation phase that check avalability of files that contain sources.
 */
class file_checker : public basic_operation {
public:
	void run() const;
};
}

#endif // __FILE_CHECKER__HPP__
