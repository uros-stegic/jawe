#ifndef __FUNCTION_DECLARATION_HPP__
#define __FUNCTION_DECLARATION_HPP__

#include <command.hpp>
#include <literals/function.hpp>
#include <string>

namespace jawe {
class FunctionDeclaration : public Command {
public:
	FunctionDeclaration(std::string, Function*);
	~FunctionDeclaration();

	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;

private:
	std::string m_name;
	Function* m_function;
};
}

#endif // __FUNCTION_DECLARATION_HPP__

