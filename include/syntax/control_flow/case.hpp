#ifndef __CASE_HPP__
#define __CASE_HPP__

#include <command.hpp>
#include <literals/primitive.hpp>

namespace jawe {
class Case : public Command {
public:
	Case(Primitive*, Command*);
	~Case();
	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;
	
	Command* get_body() const;
	Case* copy() override;

private:
	Primitive *m_case;
	Command *m_command;
};
}

#endif // __CASE_HPP__

