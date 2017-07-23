#ifndef __TYPED_NOT_EQUALS_HPP__
#define __TYPED_NOT_EQUALS_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class typed_not_equals_node : public binary_operator_node {
public:
	typed_not_equals_node(const shared_node&, const shared_node&);
};
}

#endif // __TYPED_NOT_EQUALS_HPP__
