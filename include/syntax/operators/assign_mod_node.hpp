#ifndef __ASSIGN_MOD_HPP__
#define __ASSIGN_MOD_HPP__

#include <operators/abstract_assign_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class assign_mod_node : public abstract_assign_node {
public:
	assign_mod_node(const shared_node&, const shared_node&);
};
}

#endif // __ASSIGN_MOD_HPP__
