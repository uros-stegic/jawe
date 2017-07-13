#ifndef __PRIMITIVE_HPP__
#define __PRIMITIVE_HPP__

#include <literals/literal.hpp>

namespace jawe {
class Primitive : public Literal {
public:
	Primitive();
	virtual ~Primitive() = default;
	void dump_ast(std::ostream&, int = 0) const override;

	virtual Primitive* copy() override = 0;
};
}
#endif // __PRIMITIVE_HPP__

