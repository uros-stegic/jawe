#ifndef __FUNCTION_DECOMPOSER__HPP__
#define __FUNCTION_DECOMPOSER__HPP__

#include <operations/basic_operation.hpp>
#include <syntax.hpp>

namespace jawe {
class FunctionDecomposer : public basic_operation {
public:
	void run() const;

private:
	void decompose(shared_node*) const;
};
}

#endif // __FUNCTION_DECOMPOSER__HPP__
