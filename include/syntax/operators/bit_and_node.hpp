#ifndef __BIT_AND_HPP__
#define __BIT_AND_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class bit_and_node : public binary_operator_node {
public:
	bit_and_node(const shared_node&, const shared_node&);
};
}

#endif // __BIT_AND_HPP__

