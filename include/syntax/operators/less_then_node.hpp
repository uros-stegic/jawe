#ifndef __LESS_THEN_HPP__
#define __LESS_THEN_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class less_then_node : public binary_operator_node {
public:
	less_then_node(const shared_node&, const shared_node&);
};
}

#endif // __LESS_THEN_HPP__
