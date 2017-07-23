#ifndef __TYPEOF_HPP__
#define __TYPEOF_HPP__

#include <operators/unary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class typeof_node : public unary_operator_node {
public:
	typeof_node(const shared_node&);
};
}

#endif // __TYPEOF_HPP__

