#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include <literals/abstract_object.hpp>
#include <command.hpp>
#include <vector>
#include <string>

namespace jawe {
class Function : public AbstractObject {
public:
	Function(std::vector<std::string>, Command*);
	~Function();

	Command* body() const;

	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	void print_args(std::ostream&) const;

	Function* copy() override;
	Command* get_body();

private:
	std::vector<std::string> m_args;
	Command* m_body;

};
}

#endif // __FUNCTION_HPP__

