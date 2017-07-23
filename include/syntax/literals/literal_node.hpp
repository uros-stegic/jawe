#ifndef __LITERAL_HPP__
#define __LITERAL_HPP__

#include <expr_node.hpp>
#include <string>

namespace jawe {
class literal_node : public expr_node {
public:
	literal_node(std::string);
};
}

#endif // __LITERAL_HPP__

