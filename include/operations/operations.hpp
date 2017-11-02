#ifndef __OPERATIONS_HPP__
#define __OPERATIONS_HPP__

#include <string>
#include <operations/file_checker.hpp>
#include <operations/parser.hpp>
#include <operations/printer.hpp>
#include <operations/empty_remover.hpp>
#include <operations/phaser.hpp>
#include <operations/optimizer.hpp>
#include <operations/semantic_analyzer.hpp>
#include <operations/reference_checker.hpp>
#include <operations/const_checker.hpp>
#include <operations/code_generator.hpp>

namespace jawe {
/** \brief Wrapper class around phaser object.
 *
 * NOTE: This class is non-copyable and it's only purpose
 * is to provide an interface to run variadic number of compilation
 * phases which is resolved at compile time.
 */
class operations {
public:
	operations() = delete;
	operations(const operations&) = delete;
	void operator=(const operations&) = delete;

	template<class... Phases>
		static void run_compilation() {
			phaser<Phases...> phaser;
			phaser.run();
		}
};
}

#endif // __OPERATIONS_HPP__
