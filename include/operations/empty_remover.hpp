#ifndef __EMPTY_REMOVER__HPP__
#define __EMPTY_REMOVER__HPP__

#include <operations/basic_operation.hpp>
#include <syntax.hpp>

namespace jawe {
class EmptyRemover : public basic_operation {
public:
	void run() const;

private:
	void remove(Command*) const;

	void remove(CommandBlock*) const;
	void remove(IfElse*) const;
	void remove(While*) const;
	void remove(DoWhile*) const;
	void remove(For*) const;
	void remove(Switch*) const;
	void remove(Case*) const;
	void remove(Default*) const;
	void remove(FunctionDeclaration*) const;
	void remove(Declaration*) const;
	void remove(Empty*) const;
};
}

#endif // __EMPTY_REMOVER__HPP__

