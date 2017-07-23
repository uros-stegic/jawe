#ifndef __DELETE_HPP__
#define __DELETE_HPP__

#include <operators/unary_operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class delete_node : public unary_operator_node {
public:
	delete_node(const shared_node&);
};
}

#endif // __DELETE_HPP__

