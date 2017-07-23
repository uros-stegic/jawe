#ifndef __COMMAND_BLOCK_HPP__
#define __COMMAND_BLOCK_HPP__

#include <shared_node.hpp>
#include <vector>

namespace jawe {
class command_block_node : public basic_node {
public:
	command_block_node();
	command_block_node(const shared_node&);
	command_block_node(const std::vector<shared_node>&);
	void push_back(const shared_node&);
	std::vector<shared_node> get_commands();

private:
	std::vector<shared_node> m_commands;
};
}

#endif // __COMMAND_BLOCK_HPP__

