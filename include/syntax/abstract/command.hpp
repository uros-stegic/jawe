#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <iostream>
#include <utils/mem_leak.hpp>

namespace jawe {
class Command : public LeakChecker<Command> {
public:
	virtual ~Command() = default;

	virtual void print(std::ostream&) const = 0;
	virtual void dump_ast(std::ostream&, int = 0) const = 0;
};
}

#endif // __COMMAND_HPP__

