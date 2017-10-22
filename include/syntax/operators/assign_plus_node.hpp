#ifndef __ASSIGN_PLUS_HPP__
#define __ASSIGN_PLUS_HPP__

#include <operators/abstract_assign_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class assign_plus_node : public abstract_assign_node {
public:
	assign_plus_node(const shared_node&, const shared_node&);
};
}

#endif // __ASSIGN_PLUS_HPP__
