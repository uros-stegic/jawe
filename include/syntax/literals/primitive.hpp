#ifndef __PRIMITIVE_HPP__
#define __PRIMITIVE_HPP__

#include <literals/literal.hpp>

namespace jawe {
class Primitive : public Literal {
public:
	using Literal::Literal;
	virtual ~Primitive();
	void dump_ast(std::ostream&, int = 0) const override;
};
}
#endif // __PRIMITIVE_HPP__

