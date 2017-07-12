#ifndef __UNDEFINED_HPP__
#define __UNDEFINED_HPP__

#include <literals/primitive.hpp>

namespace jawe {
class Undefined : public Primitive {
public:
	Undefined();
	~Undefined();

	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	Undefined* copy() override;
};
}
#endif // __UNDEFINED_HPP__

