#ifndef __TRUE_HPP__
#define __TRUE_HPP__

#include <literals/primitive.hpp>

namespace jawe {
class True : public Primitive {
public:
	True();
	~True();

	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;
	bool value() const;
};
}
#endif // __TRUE_HPP__

