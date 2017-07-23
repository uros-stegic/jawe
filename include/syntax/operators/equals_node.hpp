#ifndef __EQUALS_HPP__
#define __EQUALS_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class equals_node : public binary_operator_node {
public:
	equals_node(const shared_node&, const shared_node&);
};
}

#endif // __EQUALS_HPP__

