#include <utils/control.hpp>
#include <shared_node.hpp>

extern jawe::shared_node* program;

int main(int argc, char **argv)
{
	program = nullptr;

	jawe::Control::get(argc, argv).run();

	if( program == nullptr ) {
		return 0;
	}
	delete program;
	return 0;
}
