#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <string>
#include <literals/primitive_node.hpp>

namespace jawe {
class string_node : public primitive_node {
public:
	string_node(std::string);
private:
	std::string m_string;
};
}
#endif // __STRING_HPP__

