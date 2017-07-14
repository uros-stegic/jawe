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

	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	FunctionDeclaration* copy() override;
	Command* get_body();

private:
	std::string m_name;
	Function* m_function;
};
}

#endif // __FUNCTION_DECLARATION_HPP__

