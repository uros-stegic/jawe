#ifndef __LESS_OR_EQUALS_HPP__
#define __LESS_OR_EQUALS_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class less_or_equals_node : public binary_operator_node {
public:
	less_or_equals_node(const shared_node&, const shared_node&);
};
}

#endif // __LESS_OR_EQUALS_HPP__

