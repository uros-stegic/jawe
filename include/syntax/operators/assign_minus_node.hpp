#ifndef __ASSIGN_MINUS_HPP__
#define __ASSIGN_MINUS_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class assign_minus_node : public binary_operator_node {
public:
	assign_minus_node(const shared_node&, const shared_node&);
};
}

#endif // __ASSIGN_MINUS_HPP__

