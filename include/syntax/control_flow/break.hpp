#ifndef __BREAK_HPP__
#define __BREAK_HPP__

#include <command.hpp>

namespace jawe {
class Break : public Command {
public:
	Break();
	~Break();
	void print(std::ostream&) const override;
};
}

#endif // __BREAK_HPP__

