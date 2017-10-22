#ifndef __ASSIGN_DIV_HPP__
#define __ASSIGN_DIV_HPP__

#include <operators/abstract_assign_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class assign_div_node : public abstract_assign_node {
public:
	assign_div_node(const shared_node&, const shared_node&);
};
}

#endif // __ASSIGN_DIV_HPP__
