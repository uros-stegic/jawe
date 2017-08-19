#ifndef __OPERATIONS_HPP__
#define __OPERATIONS_HPP__

#include <string>
#include <operations/file_checker.hpp>
#include <operations/parser.hpp>
#include <operations/printer.hpp>
#include <operations/fn_decompose.hpp>
#include <operations/empty_remover.hpp>
#include <operations/phaser.hpp>
#include <operations/optimizer.hpp>
#include <operations/semantic_analyzer.hpp>
#include <operations/reference_checker.hpp>

namespace jawe {
class Operations {
public:
	Operations() = delete;
	Operations(const Operations&) = delete;
	void operator=(const Operations&) = delete;

	template<class... Phases>
		static void run_compilation() {
			Phaser<Phases...> phaser;
			phaser.run();
		}
};
}

#endif // __OPERATIONS_HPP__
