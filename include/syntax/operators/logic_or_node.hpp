#ifndef __LOGIC_OR_HPP__
#define __LOGIC_OR_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class logic_or_node : public binary_operator_node {
public:
	logic_or_node(const shared_node&, const shared_node&);
};
}

#endif // __LOGIC_OR_HPP__
