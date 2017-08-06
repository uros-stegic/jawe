#ifndef __FUNCTION_CALL_HPP__
#define __FUNCTION_CALL_HPP__

#include <shared_node.hpp>
#include <expr_node.hpp>
#include <vector>

namespace jawe {
class function_call_node : public expr_node {
public:
	function_call_node(const shared_node&);
	function_call_node(const shared_node&,const std::vector<shared_node>&);

	void push_back(const shared_node&);

	shared_node get_expr();
	std::vector<shared_node> get_args();

private:
	shared_node m_expr;
	std::vector<shared_node> m_args;
};
}

#endif // __FUNCTION_CALL_HPP__
