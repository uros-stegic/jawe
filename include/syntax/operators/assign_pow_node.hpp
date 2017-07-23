#ifndef __ASSIGN_POW_HPP__
#define __ASSIGN_POW_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class assign_pow_node : public binary_operator_node {
public:
	assign_pow_node(const shared_node&, const shared_node&);
};
}

#endif // __ASSIGN_POW_HPP__

