#ifndef __DEFAULT_HPP__
#define __DEFAULT_HPP__

#include <command.hpp>

namespace jawe {
class Default : public Command {
public:
	Default(Command*);
	~Default();
	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	Command* get_body() const;
	Default* copy() override;
	
private:
	Command *m_command;
};
}

#endif // __DEFAULT_HPP__

