#ifndef __INCREMENT_HPP__
#define __INCREMENT_HPP__

#include <operators/unary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class increment_node : public unary_operator_node {
public:
	increment_node(const shared_node&);
};
}

#endif // __INCREMENT_HPP__

