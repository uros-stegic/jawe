#ifndef __HOISTER_HPP__
#define __HOISTER_HPP__

#include <transformations/basic_transformation.hpp>
#include <syntax.hpp>
#include <optional>

namespace jawe {
class Hoister : public BasicTransformation {
public:
	void run() const;

private:
	void remove(const shared_node&, const shared_node&) const;
	void decouple(const shared_node&, const shared_node&, const shared_node&) const;
	std::optional<shared_node> get_decl_ass_op(const shared_node& node) const;
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
