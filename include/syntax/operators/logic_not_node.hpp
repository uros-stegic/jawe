#ifndef __LOGIC_NOT_HPP__
#define __LOGIC_NOT_HPP__

#include <operators/unary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class logic_not_node : public unary_operator_node {
public:
	logic_not_node(const shared_node&);
};
}

#endif // __LOGIC_NOT_HPP__

