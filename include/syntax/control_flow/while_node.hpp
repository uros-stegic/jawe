#ifndef __WHILE_HPP__
#define __WHILE_HPP__

#include <shared_node.hpp>

namespace jawe {
class while_node : public basic_node {
public:
	while_node(const shared_node&, const shared_node&);

	shared_node get_expr() const;
	shared_node get_body() const;

private:
	shared_node m_expr, m_body;
};
}

#endif // __WHILE_HPP__
