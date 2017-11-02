#ifndef __EMPTY_REMOVER__HPP__
#define __EMPTY_REMOVER__HPP__

#include <operations/basic_operation.hpp>
#include <syntax.hpp>

namespace jawe {
/** \brief Operation pass that eliminates all empty statments from the AST.
 */
class empty_remover : public basic_operation {
public:
	void run() const;

private:
	void remove(const shared_node&, const shared_node&) const;
	void remove_impl(const shared_node&, const shared_node&) const;

};
}

#endif // __EMPTY_REMOVER__HPP__
