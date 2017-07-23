#ifndef __DEFAULT_HPP__
#define __DEFAULT_HPP__

#include <shared_node.hpp>

namespace jawe {
class default_node : public basic_node {
public:
	default_node(const shared_node&);
	
	shared_node get_body() const;
	
private:
	shared_node m_command;
};
}

#endif // __DEFAULT_HPP__

