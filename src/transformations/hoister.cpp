#include <transformations/hoister.hpp>

using namespace jawe;

extern Ast* program;

void Hoister::transform() const
{
	auto visitor = compose{
		[](auto* node) {
			node = node;
		}
	};
	visitor(program);
}

