#ifndef __DIVIDE_HPP__
#define __DIVIDE_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class divide_node : public binary_operator_node {
public:
	divide_node(const shared_node&, const shared_node&);
};
}

#endif // __DIVIDE_HPP__

