#ifndef __ASSIGN_MUL_HPP__
#define __ASSIGN_MUL_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class assign_mul_node : public binary_operator_node {
public:
	assign_mul_node(const shared_node&, const shared_node&);
};
}

#endif // __ASSIGN_MUL_HPP__

