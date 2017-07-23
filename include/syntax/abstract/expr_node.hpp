#ifndef __EXPR_HPP__
#define __EXPR_HPP__

#include <shared_node.hpp>

namespace jawe {
class expr_node : public basic_node {
public:
	expr_node(std::string symbol);
};
}


#endif // __EXPR_HPP__

