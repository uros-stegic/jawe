#ifndef __LOGICAL_LITERAL_HPP__
#define __LOGICAL_LITERAL_HPP__

#include <literals/primitive_node.hpp>
#include <string>

namespace jawe {
class logical_literal_node : public primitive_node {
public:
	logical_literal_node(std::string symbol);
};
}



#endif // __LOGICAL_LITERAL_HPP__
