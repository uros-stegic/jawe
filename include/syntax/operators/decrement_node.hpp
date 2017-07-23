#ifndef __DECREMENT_HPP__
#define __DECREMENT_HPP__

#include <operators/unary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class decrement_node : public unary_operator_node {
public:
	decrement_node(const shared_node&);
};
}

#endif // __DECREMENT_HPP__

