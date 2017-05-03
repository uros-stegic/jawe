#include <control.hpp>
#include <ast.hpp>

extern jawe::Ast* program;

int main(int argc, char **argv)
{
	jawe::Control proc(argc, argv);
	proc.run();

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

