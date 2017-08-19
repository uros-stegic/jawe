#ifndef __CONST_DECLARATION_HPP__
#define __CONST_DECLARATION_HPP__

#include <variables/declaration_node.hpp>

namespace jawe {
class const_declaration_node : public declaration_node {
public:
	const_declaration_node(const shared_node&);
};
}

#endif // __CONST_DECLARATION_HPP__
