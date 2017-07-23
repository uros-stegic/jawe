#ifndef __DO_WHILE_HPP__
#define __DO_WHILE_HPP__

#include <shared_node.hpp>

namespace jawe {
class do_while_node : public basic_node {
public:
	do_while_node(const shared_node&,const shared_node&);

	shared_node get_expr() const;
	shared_node get_body() const;

private:
	shared_node m_body, m_cond;
};
}

#endif // __DO_WHILE_HPP__

