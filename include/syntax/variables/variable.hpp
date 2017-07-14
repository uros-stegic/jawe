#ifndef __VARIABLE_HPP__
#define __VARIABLE_HPP__

#include <string>
#include <expr.hpp>

namespace jawe {
class Variable : public Expr {
public:
	Variable(std::string);
	~Variable();
	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	Variable* copy() override;

private:
	std::string m_name;
};
}

#endif // __VARIABLE_HPP__

