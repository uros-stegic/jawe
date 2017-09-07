#ifndef __ASSEMBLY_GENERATOR__HPP__
#define __ASSEMBLY_GENERATOR__HPP__

#include <operations/basic_operation.hpp>

namespace jawe {
class assembly_generator : public basic_operation {
public:
	void run() const;
};
}

#endif // __ASSEMBLY_GENERATOR__HPP__
