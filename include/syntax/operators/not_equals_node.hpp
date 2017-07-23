#ifndef __NOT_EQUALS_HPP__
#define __NOT_EQUALS_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class not_equals_node : public binary_operator_node {
public:
	not_equals_node(const shared_node&, const shared_node&);
};
}

#endif // __NOT_EQUALS_HPP__

