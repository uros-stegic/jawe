#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include <literals/abstract_object_node.hpp>
#include <shared_node.hpp>
#include <vector>
#include <string>

namespace jawe {
class function_object_node : public abstract_object_node {
public:
	function_object_node(const std::vector<std::string>&, const shared_node&, std::string);

	shared_node get_body();
	std::vector<std::string> get_args();

private:
	std::vector<std::string> m_args;
	shared_node m_body;

};
}

#endif // __FUNCTION_HPP__

