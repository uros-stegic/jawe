#ifndef __BIT_NOT_HPP__
#define __BIT_NOT_HPP__

#include <operators/unary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class bit_not_node : public unary_operator_node {
public:
	bit_not_node(const shared_node&);
};
}

#endif // __BIT_NOT_HPP__

