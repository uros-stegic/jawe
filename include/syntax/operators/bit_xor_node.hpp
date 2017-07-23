#ifndef __BIT_XOR_HPP__
#define __BIT_XOR_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class bit_xor_node : public binary_operator_node {
public:
	bit_xor_node(const shared_node&, const shared_node&);
};
}

#endif // __BIT_XOR_HPP__

