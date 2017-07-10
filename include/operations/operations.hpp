#ifndef __OPERATIONS_HPP__
#define __OPERATIONS_HPP__

#include <string>
#include <operations/file_checker.hpp>
#include <operations/parser.hpp>
#include <operations/phaser.hpp>

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

