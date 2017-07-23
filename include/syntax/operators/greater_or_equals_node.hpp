#ifndef __GREATER_OR_EQUALS_HPP__
#define __GREATER_OR_EQUALS_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class greater_or_equals_node : public binary_operator_node {
public:
	greater_or_equals_node(const shared_node&, const shared_node&);
};
}

#endif // __GREATER_OR_EQUALS_HPP__

