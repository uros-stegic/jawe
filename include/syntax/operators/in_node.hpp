#ifndef __IN_HPP__
#define __IN_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class in_node : public binary_operator_node {
public:
	in_node(const shared_node&, const shared_node&);
};
}

#endif // __IN_HPP__

