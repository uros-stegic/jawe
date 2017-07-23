#ifndef __UPLUS_HPP__
#define __UPLUS_HPP__

#include <operators/unary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class uplus_node : public unary_operator_node {
public:
	uplus_node(const shared_node&);
};
}

#endif // __UPLUS_HPP__

