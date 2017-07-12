#ifndef __NULL_HPP__
#define __NULL_HPP__

#include <literals/primitive.hpp>

namespace jawe {
class Null : public Primitive {
public:
	Null();
	~Null();

	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	Null* copy() override;
};
}
#endif // __NULL_HPP__

