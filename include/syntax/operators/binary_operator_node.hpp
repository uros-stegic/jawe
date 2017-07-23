#ifndef __BINARY_OPERATOR_HPP__
#define __BINARY_OPERATOR_HPP__

#include <string>
#include <iostream>

#include <shared_node.hpp>
#include <operators/operator_node.hpp>

namespace jawe {
class binary_operator_node : public operator_node {
public:
	binary_operator_node(const shared_node&, const shared_node&, std::string);

	shared_node get_left() const;
	shared_node get_right() const;

private:
	shared_node m_left, m_right;
};
}

#endif // __BINARY_OPERATOR_HPP__

