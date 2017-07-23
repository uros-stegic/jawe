#ifndef __CASE_HPP__
#define __CASE_HPP__

#include <shared_node.hpp>
#include <literals/primitive_node.hpp>

namespace jawe {
class case_node : public basic_node {
public:
	case_node(const primitive_node&, const shared_node&);
	shared_node get_body() const;

private:
	primitive_node m_case;
	shared_node m_command;
};
}

#endif // __CASE_HPP__

