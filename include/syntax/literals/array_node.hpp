#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <literals/abstract_object_node.hpp>
#include <vector>
#include <shared_node.hpp>

namespace jawe {
class array_node : public abstract_object_node {
public:
	array_node();
	array_node(const std::vector<shared_node>&);

	void push_back(const shared_node&);

private:
	std::vector<shared_node> m_elements;
};
}

#endif // __ARRAY_HPP__

