#ifndef __FOR_HPP__
#define __FOR_HPP__

#include <shared_node.hpp>

namespace jawe {
class for_node : public basic_node {
public:
	for_node(const shared_node&, const shared_node&, const shared_node&, const shared_node&);
	
	shared_node get_expr() const;
	shared_node get_body() const;
	shared_node get_init() const;
	shared_node get_post() const;

private:
	shared_node m_init, m_cond, m_post, m_body;
};
}

#endif // __FOR_HPP__

