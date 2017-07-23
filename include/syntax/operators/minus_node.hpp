#ifndef __MINUS_HPP__
#define __MINUS_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class minus_node : public binary_operator_node {
public:
	minus_node(const shared_node&, const shared_node&);
};
}

#endif // __MINUS_HPP__

