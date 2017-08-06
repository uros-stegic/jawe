#ifndef __UNARY_OPERATOR_HPP__
#define __UNARY_OPERATOR_HPP__

#include <operators/operator_node.hpp>
#include <shared_node.hpp>
#include <iostream>

namespace jawe {
class unary_operator_node : public operator_node {
public:
	unary_operator_node(const shared_node&, std::string);

	shared_node get_operand() const;

private:
	shared_node m_operand;
};
}

#endif // __UNARY_OPERATOR_HPP__
