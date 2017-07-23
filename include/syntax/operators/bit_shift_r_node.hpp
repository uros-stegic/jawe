#ifndef __BIT_SHIFT_RIGHT_HPP__
#define __BIT_SHIFT_RIGHT_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class bit_shift_r_node : public binary_operator_node {
public:
	bit_shift_r_node(const shared_node&, const shared_node&);
};
}

#endif // __BIT_SHIFT_RIGHT_HPP__

