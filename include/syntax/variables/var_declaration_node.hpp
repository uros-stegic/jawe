#ifndef __VAR_DECLARATION_HPP__
#define __VAR_DECLARATION_HPP__

#include <variables/declaration_node.hpp>

namespace jawe {
class var_declaration_node : public declaration_node {
public:
	var_declaration_node(const shared_node&);

};
}

#endif // __VAR_DECLARATION_HPP__
