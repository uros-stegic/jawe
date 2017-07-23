#ifndef __FALSE_HPP__
#define __FALSE_HPP__

#include <literals/logical_literal_node.hpp>

namespace jawe {
class false_node : public logical_literal_node {
public:
	false_node();
};
}
#endif // __FALSE_HPP__

