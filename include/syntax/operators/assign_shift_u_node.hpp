#ifndef __ASSIGN_SHIFT_U_HPP__
#define __ASSIGN_SHIFT_U_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class assign_shift_u_node : public binary_operator_node {
public:
	assign_shift_u_node(const shared_node&, const shared_node&);
};
}

#endif // __ASSIGN_SHIFT_U_HPP__
