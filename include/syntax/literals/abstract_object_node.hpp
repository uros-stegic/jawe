#ifndef __ABSTRACT_OBJECT_HPP__
#define __ABSTRACT_OBJECT_HPP__

#include <literals/literal_node.hpp>
#include <string>

namespace jawe {
class abstract_object_node : public literal_node {
public:
	abstract_object_node(std::string);
};
}

#endif // __ABSTRACT_OBJECT_HPP__

