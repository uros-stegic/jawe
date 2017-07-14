#ifndef __BREAK_HPP__
#define __BREAK_HPP__

#include <command.hpp>

namespace jawe {
class Break : public Command {
public:
	Break();
	~Break();
	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	Break* copy() override;
};
}

#endif // __BREAK_HPP__

