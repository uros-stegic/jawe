#ifndef __FALSE_HPP__
#define __FALSE_HPP__

#include <literals/primitive.hpp>

namespace jawe {
class False : public Primitive {
public:
	False();
	~False();

	void print(std::ostream&, int = 0) const override;
	void dump_ast(std::ostream&, int = 0) const override;

	bool value() const;

	False* copy() override;
};
}
#endif // __FALSE_HPP__

