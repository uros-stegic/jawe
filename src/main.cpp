#include <utils/control.hpp>
#include <ast.hpp>

extern jawe::Ast* program;

int main(int argc, char **argv)
{
	program = nullptr;

	jawe::Control::get(argc, argv).run();

	if( program == nullptr ) {
		return 0;
	}
	delete program;
	std::cerr << std::endl << "~~~~~~~~~~~~~~~~~~~~" << std::endl;
	if( !program->check() ) {
		std::cerr << "Program has failed to deallocate " << program->get() << " instances." << std::endl;
	}
	else {
		std::cout << "Program finished without memory leaks" << std::endl;
	}
	std::cerr << std::endl << "~~~~~~~~~~~~~~~~~~~~" << std::endl;

	return 0;
}

