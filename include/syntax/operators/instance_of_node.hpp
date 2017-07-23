#ifndef __INSTANCE_OF_HPP__
#define __INSTANCE_OF_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class instance_of_node : public binary_operator_node {
public:
	instance_of_node(const shared_node&, const shared_node&);
};
}

#endif // __INSTANCE_OF_HPP__

