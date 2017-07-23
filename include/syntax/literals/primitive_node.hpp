#ifndef __PRIMITIVE_HPP__
#define __PRIMITIVE_HPP__

#include <literals/literal_node.hpp>
#include <string>

namespace jawe {
class primitive_node : public literal_node {
public:
	primitive_node(std::string symbol);
};
}
#endif // __PRIMITIVE_HPP__

