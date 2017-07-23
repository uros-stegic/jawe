#ifndef __UMINUS_HPP__
#define __UMINUS_HPP__

#include <operators/unary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class uminus_node : public unary_operator_node {
public:
	uminus_node(const shared_node&);
};
}

#endif // __UMINUS_HPP__

