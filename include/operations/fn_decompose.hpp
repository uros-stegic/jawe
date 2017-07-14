#ifndef __FUNCTION_DECOMPOSER__HPP__
#define __FUNCTION_DECOMPOSER__HPP__

#include <operations/basic_operation.hpp>
#include <syntax.hpp>

namespace jawe {
class FunctionDecomposer : public basic_operation {
public:
	void run() const;

private:
	void decompose(Command*) const;

	void decompose(CommandBlock*) const;
	void decompose(IfElse*) const;
	void decompose(While*) const;
	void decompose(DoWhile*) const;
	void decompose(For*) const;
	void decompose(Switch*) const;
	void decompose(Case*) const;
	void decompose(Default*) const;
	void decompose(FunctionDeclaration*) const;
	void decompose(Declaration*) const;
};
}

#endif // __FUNCTION_DECOMPOSER__HPP__

