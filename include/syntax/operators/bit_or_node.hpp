#ifndef __BIT_OR_HPP__
#define __BIT_OR_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class bit_or_node : public binary_operator_node {
public:
	bit_or_node(const shared_node&, const shared_node&);
};
}

#endif // __BIT_OR_HPP__

