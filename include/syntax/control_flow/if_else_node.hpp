#ifndef __IF_ELSE_HPP__
#define __IF_ELSE_HPP__

#include <shared_node.hpp>

namespace jawe {
class if_else_node : public basic_node {
public:
	if_else_node(const shared_node&, const shared_node&, const shared_node& = nullptr);

	shared_node get_expr() const;
	shared_node get_if() const;
	shared_node get_else() const;

private:
	shared_node m_if, m_expr, m_else;
};
}

#endif // __IF_ELSE_HPP__

