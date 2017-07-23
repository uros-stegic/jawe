#ifndef __LET_DECLARATION_HPP__
#define __LET_DECLARATION_HPP__

#include <variables/declaration_node.hpp>

namespace jawe {
class let_declaration_node : public declaration_node {
public:
	let_declaration_node(const shared_node&);

};
}

#endif // __LET_DECLARATION_HPP__

