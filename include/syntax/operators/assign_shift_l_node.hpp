#ifndef __ASSIGN_SHIFT_L_HPP__
#define __ASSIGN_SHIFT_L_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class assign_shift_l_node : public binary_operator_node {
public:
	assign_shift_l_node(const shared_node&, const shared_node&);
};
}

#endif // __ASSIGN_SHIFT_L_HPP__

