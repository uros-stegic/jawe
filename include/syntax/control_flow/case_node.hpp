#ifndef __CASE_HPP__
#define __CASE_HPP__

#include <shared_node.hpp>

namespace jawe {
class case_node : public basic_node {
public:
	case_node(const shared_node&, const shared_node&);
	shared_node get_body() const;
	shared_node get_case() const;

private:
	shared_node m_case;
	shared_node m_body;
};
}

#endif // __CASE_HPP__
