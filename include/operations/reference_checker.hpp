#ifndef __REFERENCE_CHECKER_HPP__
#define __REFERENCE_CHECKER_HPP__

#include <operations/basic_operation.hpp>
#include <syntax.hpp>
#include <optional>

namespace jawe {
class reference_checker : public basic_operation {
public:
	void run();
private:
	std::vector<std::vector<std::string>> m_scopes;
	void check(const shared_node& root);
	bool find_variable(const std::string&) const;
	void print_stacks() const;
	std::string get_decl_var_name(const shared_node& root);

};
}

#endif // __REFERENCE_CHECKER_HPP__
