#ifndef __PRINTER__HPP__
#define __PRINTER__HPP__

#include <operations/basic_operation.hpp>
#include <abstract/shared_node.hpp>

namespace jawe {

/** \brief Operation pass that prints AST to the standard output.
 *
 * Depending on a flags that are passed to the compiler, this
 * object is able to print back the source code but also to provide
 * AST view (with memory addresses of AST nodees printed out if --memory
 * flag is provided).
 */
class printer : public basic_operation {
public:
	void run() const;
private:
	void dump_program(const shared_node&, int) const;
	void dump_ast(const shared_node&, int) const;
};
}

#endif // __PRINTER__HPP__
