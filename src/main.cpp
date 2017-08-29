#include <utils/control.hpp>
#include <utils/lambda_composer.hpp>
#include <shared_node.hpp>
#include <syntax.hpp>

#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>

extern jawe::shared_node* program;

int main(int argc, char **argv)
{
	program = nullptr;

	jawe::control::get(argc, argv).run();

	if( program == nullptr ) {
		return 0;
	}

	delete program;

	
	if( jawe::control::get().check_leaks() ) {
		/* Checking for memory leaks */
		std::cerr << std::endl << "~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::visit(jawe::lambda_composer {
			[](auto program) {
				if( !program->check() ) {
					std::cerr << "Program has failed to deallocate " << program->get() << " instances." << std::endl;
					jawe::leak_previewer::show_leaked(program);
				}
				else {
					std::cout << "Program finished without memory leaks" << std::endl;
				}

			}
		}, **program);
		std::cerr << std::endl << "~~~~~~~~~~~~~~~~~~~~" << std::endl;
	}

	return 0;
}
