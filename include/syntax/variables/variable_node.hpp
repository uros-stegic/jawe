#ifndef __VARIABLE_HPP__
#define __VARIABLE_HPP__

#include <string>
#include <expr_node.hpp>

namespace jawe {
class variable_node : public expr_node {
public:
	variable_node(std::string);

private:
	std::string m_name;
};
}

#endif // __VARIABLE_HPP__

