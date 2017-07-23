#ifndef __OPERATOR_HPP__
#define __OPERATOR_HPP__

#include <expr_node.hpp>

namespace jawe {
class operator_node : public expr_node {
public:
	operator_node(std::string);

private:
	std::string m_symbol;
};
}

#endif // __OPERATOR_HPP__

