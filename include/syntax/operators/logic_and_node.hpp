#ifndef __LOGIC_AND_HPP__
#define __LOGIC_AND_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class logic_and_node : public binary_operator_node {
public:
	logic_and_node(const shared_node&, const shared_node&);
};
}

#endif // __LOGIC_AND_HPP__

