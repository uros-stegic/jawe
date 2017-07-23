#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <map>
#include <utility>
#include <string>
#include <literals/abstract_object_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class object_node : public abstract_object_node {
public:
	object_node();
	object_node(const std::map<std::string, shared_node>&);
	void set(std::string, shared_node);

private:
	std::map<std::string, shared_node> m_pairs;
};
}

#endif // __OBJECT_HPP__

