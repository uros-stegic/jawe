#ifndef __GREATER_THEN_HPP__
#define __GREATER_THEN_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class greater_then_node : public binary_operator_node {
public:
	greater_then_node(const shared_node&, const shared_node&);
};
}

#endif // __GREATER_THEN_HPP__

