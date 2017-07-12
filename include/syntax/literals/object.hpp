#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <map>
#include <utility>
#include <string>
#include <literals/abstract_object.hpp>

namespace jawe {
class Object : public AbstractObject {
public:
	Object(const std::map<std::string, Expr*>&);
	~Object();
	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;
	void dump_pair_ast(std::ostream&, const std::pair<std::string, Expr*>&, int = 0) const;
	Object* copy() override;

private:
	std::map<std::string, Expr*> m_pairs;

	void print_pair(std::ostream&, const std::pair<std::string, Expr*>&) const;
};
}

#endif // __OBJECT_HPP__

