#ifndef __POST_DECREMENT_HPP__
#define __POST_DECREMENT_HPP__

#include <operators/unary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class post_decrement_node : public unary_operator_node {
public:
	post_decrement_node(const shared_node&);
};
}

#endif // __POST_DECREMENT_HPP__

