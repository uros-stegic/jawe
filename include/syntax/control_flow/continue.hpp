#ifndef __CONTINUE_HPP__
#define __CONTINUE_HPP__

#include <command.hpp>

namespace jawe {
class Continue : public Command {
public:
	Continue();
	~Continue();
	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;
};
}

#endif // __CONTINUE_HPP__

