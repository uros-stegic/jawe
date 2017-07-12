#ifndef __NAN_HPP__
#define __NAN_HPP__

#include <literals/primitive.hpp>

namespace jawe {
class Nan : public Primitive {
public:
	Nan();
	~Nan();

	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	Nan* copy() override;
};
}
#endif // __NAN_HPP__

