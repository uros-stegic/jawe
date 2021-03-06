#ifndef __TIMES_HPP__
#define __TIMES_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class times_node : public binary_operator_node {
public:
	times_node(const shared_node&, const shared_node&);
};
}

#endif // __TIMES_HPP__

