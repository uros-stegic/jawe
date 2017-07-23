#ifndef __RETURN_HPP__
#define __RETURN_HPP__

#include <shared_node.hpp>
#include <expr_node.hpp>

namespace jawe {
class return_node : public basic_node {
public:
	return_node(const expr_node&);

	expr_node get_expr() const;
private:
	expr_node m_expr;
};
}

#endif // __RETURN_HPP__

