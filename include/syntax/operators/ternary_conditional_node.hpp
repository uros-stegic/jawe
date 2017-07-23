#ifndef __TERNARY_CONDITIONAL_HPP__
#define __TERNARY_CONDITIONAL_HPP__

#include <operators/ternary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class ternary_conditional_node : public ternary_operator_node {
public:
	ternary_conditional_node(const shared_node&, const shared_node&, const shared_node&);
};
}

#endif // __TERNARY_CONDITIONAL_HPP__

