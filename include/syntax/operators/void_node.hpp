#ifndef __VOID_HPP__
#define __VOID_HPP__

#include <operators/unary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class void_node : public unary_operator_node {
public:
	void_node(const shared_node&);
};
}

#endif // __VOID_HPP__

