#ifndef __EMPTY_HPP__
#define __EMPTY_HPP__

#include <command.hpp>

namespace jawe {
class Empty : public Command {
public:
	Empty();
	~Empty();
	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;
};
}

#endif // __EMPTY_HPP__

