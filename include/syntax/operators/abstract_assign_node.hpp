#ifndef __ABSTRACT_ASSIGN_HPP__
#define __ABSTRACT_ASSIGN_HPP__

#include <operators/binary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class abstract_assign_node : public binary_operator_node {
public:
	abstract_assign_node(const shared_node&, const shared_node&, std::string);
};
}

#endif // __ABSTRACT_ASSIGN_HPP__
