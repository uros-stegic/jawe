#ifndef __UNDEFINED_HPP__
#define __UNDEFINED_HPP__

#include <literals/literal.hpp>

namespace jawe {
class Undefined : public Literal {
public:
	Undefined();
	~Undefined();

	void print(std::ostream&) const override;
};
}
#endif // __UNDEFINED_HPP__

