#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <ast.hpp>

namespace jawe {
class Command : public Ast {
public:
	virtual ~Command();
};
}

#endif // __COMMAND_HPP__

