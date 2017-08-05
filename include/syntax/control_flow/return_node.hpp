#ifndef __RETURN_HPP__
#define __RETURN_HPP__

#include <shared_node.hpp>

namespace jawe {
class return_node : public basic_node {
public:
	return_node(const shared_node&);

	shared_node get_expr() const;
private:
	shared_node m_expr;
};
}

#endif // __RETURN_HPP__
