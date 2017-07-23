#ifndef __POWER_HPP__
#define __POWER_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class power_node : public binary_operator_node {
public:
	power_node(const shared_node&, const shared_node&);
};
}

#endif // __POWER_HPP__

