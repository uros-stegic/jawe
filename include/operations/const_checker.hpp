#ifndef __CONST_CHECKER_HPP__
#define __CONST_CHECKER_HPP__

#include <operations/basic_operation.hpp>
#include <syntax.hpp>
#include <optional>
#include <utils/scope.hpp>

namespace jawe {
using namespace utils;
class const_checker : public basic_operation {
public:
	void run();
private:
  scope<utils::empty> m_scopes;

	void check(const shared_node& root);
	void print_stacks() const;

	std::string get_decl_var_name(const shared_node& root);
};
}

#endif // __CONST_CHECKER_HPP__
