#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <literals/abstract_object.hpp>
#include <vector>
#include <expr.hpp>

namespace jawe {
class Array : public AbstractObject {
public:
	Array();
	Array(const std::vector<Expr*>&);
	~Array();

	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;
	void insert(Expr*);

	Array* copy() override;

private:
	std::vector<Expr*> m_elements;
};
}

#endif // __ARRAY_HPP__

