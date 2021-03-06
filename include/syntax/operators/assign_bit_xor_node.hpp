#ifndef __ASSIGN_BIT_XOR_HPP__
#define __ASSIGN_BIT_XOR_HPP__

#include <operators/abstract_assign_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class assign_bit_xor_node : public abstract_assign_node {
public:
	assign_bit_xor_node(const shared_node&, const shared_node&);
};
}

#endif // __ASSIGN_BIT_XOR_HPP__
