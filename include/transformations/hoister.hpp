#ifndef __HOISTER_HPP__
#define __HOISTER_HPP__

#include <transformations/basic_transformation.hpp>
#include <syntax.hpp>

namespace jawe {
class Hoister : public BasicTransformation {
public:
	void transform() const;

private:
	void decouple(shared_node*) const;
	// void decouple(CommandBlock*) const;
	// void decouple(IfElse*) const;
	// void decouple(While*) const;
	// void decouple(DoWhile*) const;
	// void decouple(For*) const;
	// void decouple(Switch*) const;
	// void decouple(Case*) const;
	// void decouple(Default*) const;
	// void decouple(FunctionDeclaration*) const;
	// void decouple(Declaration*) const;
	//
	// CommandBlock* find_top_block(Command*) const;
};
}

#endif // __HOISTER_HPP__
