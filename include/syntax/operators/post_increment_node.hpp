#ifndef __POST_INCREMENT_HPP__
#define __POST_INCREMENT_HPP__

#include <operators/unary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class post_increment_node : public unary_operator_node {
public:
	post_increment_node(const shared_node&);
};
}

#endif // __POST_INCREMENT_HPP__

