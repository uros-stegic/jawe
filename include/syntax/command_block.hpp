#ifndef __COMMAND_BLOCK_HPP__
#define __COMMAND_BLOCK_HPP__

#include <command.hpp>
#include <vector>

namespace jawe {
class CommandBlock : public Command {
public:
	CommandBlock(Command*);
	CommandBlock(const std::vector<Command*>&);
	~CommandBlock();
	void print(std::ostream&) const override;
	void insert(Command*);
	void dump_ast(std::ostream&, int = 0) const override;

private:
	std::vector<Command*> m_commands;
};
}

#endif // __COMMAND_BLOCK_HPP__

