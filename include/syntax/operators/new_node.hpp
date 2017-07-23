#ifndef __NEW_HPP__
#define __NEW_HPP__

#include <operators/unary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class new_node : public unary_operator_node {
public:
	new_node(const shared_node&);
};
}

#endif // __NEW_HPP__

