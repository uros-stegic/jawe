#ifndef __HOISTER_HPP__
#define __HOISTER_HPP__

#include <transformations/basic_transformation.hpp>
#include <syntax.hpp>
#include <optional>

namespace jawe {

/** \brief Transformation of AST that hoist variables according to ES standard.
 *
 * Hoists function declarations to the beginning of the global scope (or to the beginning of an outer function),
 * variables declared with var keyword just after them, and variables declared with let keyword to the beginning of a
 * block.
 */
class hoister : public basic_transformation {
public:
	/** Starts the transformation.
	 *
	 * Calls jawe::hoister::decouple() with global AST root as an argument.
	 */
	void run() const;

private:
	//void remove(const shared_node&, const shared_node&) const;
	
	/**
	 * Does the actual work of decoupling variable declarations from their definitions, and hoists them according to ES
	 * standard.
	 *
	 * It is a recursive function that memoizes (through arguments) where should corresponding let/var declarations
	 * get hoisted.
	 *
	 * @param root current AST node in recursive descent.
	 * @param parent_var AST node to which will var declarations get hoisted.
	 * @param parent_let AST node to which will let declarations get hoisted.
	 */
	void decouple(const shared_node& root, const shared_node& parent_var, const shared_node& parent_let) const;

	/**
	 * Returns std::optional of it's argument if argument is of type jawe::assign_node, empty std::optional otherwise.
	 *
	 * @param node AST node to be examined.
	 */
	std::optional<shared_node> get_decl_ass_op(const shared_node& node) const;
};
}

#endif // __HOISTER_HPP__

