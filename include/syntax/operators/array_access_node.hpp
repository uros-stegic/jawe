#ifndef __ARRAY_ACCESS_HPP__
#define __ARRAY_ACCESS_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class array_access_node : public binary_operator_node {
public:
	array_access_node(const shared_node&, const shared_node&);
};
}

#endif // __ARRAY_ACCESS_HPP__
