#ifndef __ASSIGN_MUL_HPP__
#define __ASSIGN_MUL_HPP__

#include <operators/abstract_assign_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class assign_mul_node : public abstract_assign_node {
public:
	assign_mul_node(const shared_node&, const shared_node&);
};
}

#endif // __ASSIGN_MUL_HPP__
