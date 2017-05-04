#ifndef __NULL_HPP__
#define __NULL_HPP__

#include <literals/literal.hpp>

namespace jawe {
class Null : public Literal {
public:
	Null();
	~Null();

	void print(std::ostream&) const override;
};
}
#endif // __NULL_HPP__

