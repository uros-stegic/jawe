#ifndef __ASSIGN_SHIFT_R_HPP__
#define __ASSIGN_SHIFT_R_HPP__

#include <operators/abstract_assign_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class assign_shift_r_node : public abstract_assign_node {
public:
	assign_shift_r_node(const shared_node&, const shared_node&);
};
}

#endif // __ASSIGN_SHIFT_R_HPP__
