#ifndef __SWITCH_HPP__
#define __SWITCH_HPP__

#include <shared_node.hpp>
#include <vector>

namespace jawe {
class switch_node : public basic_node {
public:
	switch_node(const shared_node&, const std::vector<shared_node>&);

	shared_node get_expr();
	std::vector<shared_node>& get_cases();

private:
	shared_node m_expr;
	std::vector<shared_node> m_cases;
};
}

#endif // __SWITCH_HPP__
