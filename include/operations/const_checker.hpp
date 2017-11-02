#ifndef __CONST_CHECKER_HPP__
#define __CONST_CHECKER_HPP__

#include <operations/basic_operation.hpp>
#include <syntax.hpp>
#include <optional>
#include <utils/scope.hpp>

namespace jawe {
using namespace utils;
/** \brief Operation pass that checks for assignments to const declared variables
 *
 * jawe::const_checker class is part of semantic analyzer that traverses through
 * AST and terminates the compilation with an error message if there is assignment
 * to a const declared variable in the source code. This does not include initialization
 * of a const variable.
 */
class const_checker : public basic_operation {
public:
	void run();
private:
  scope<bool> m_scopes;

	void check(const shared_node& root);
	void print_stacks() const;

	std::string get_decl_var_name(const shared_node& root);
};
}

#endif // __CONST_CHECKER_HPP__
