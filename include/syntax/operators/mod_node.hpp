#ifndef __MOD_HPP__
#define __MOD_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class mod_node : public binary_operator_node {
public:
	mod_node(const shared_node&, const shared_node&);
};
}

#endif // __MOD_HPP__

