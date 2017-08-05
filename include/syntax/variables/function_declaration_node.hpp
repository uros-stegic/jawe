#ifndef __FUNCTION_DECLARATION_HPP__
#define __FUNCTION_DECLARATION_HPP__

#include <shared_node.hpp>
#include <string>

namespace jawe {
class function_declaration_node : public basic_node {
public:
	function_declaration_node(std::string, const shared_node&);

	shared_node get_body();
	shared_node get_function_object();
	std::string get_name() const;

private:
	std::string m_name;
	shared_node m_function_object;
};
}

#endif // __FUNCTION_DECLARATION_HPP__
