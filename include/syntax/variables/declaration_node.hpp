#ifndef __DECLARATION_HPP__
#define __DECLARATION_HPP__

#include <shared_node.hpp>
#include <string>

namespace jawe {
enum qualifier { QVar, QLet, QConst };
class declaration_node : public basic_node {
public:
	declaration_node(const shared_node&, qualifier, std::string);
	qualifier get_qualifier() const;
	shared_node get_expr() const;
private:
	shared_node m_expr;
	qualifier m_qualifier;
};
}

#endif // __DECLARATION_HPP__
