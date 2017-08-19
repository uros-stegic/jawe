#ifndef __PRINTER__HPP__
#define __PRINTER__HPP__

#include <operations/basic_operation.hpp>
#include <abstract/shared_node.hpp>

namespace jawe {
class printer : public basic_operation {
public:
	void run() const;
private:
	void dump_program(const shared_node&, int) const;
	void dump_ast(const shared_node&, int) const;
};
}

#endif // __PRINTER__HPP__
