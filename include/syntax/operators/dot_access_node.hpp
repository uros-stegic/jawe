#ifndef __DOT_ACCESS_HPP__
#define __DOT_ACCESS_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class dot_access_node : public binary_operator_node {
public:
	dot_access_node(const shared_node&, const shared_node&);
};
}

#endif // __DOT_ACCESS_HPP__

