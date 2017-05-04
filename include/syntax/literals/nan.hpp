#ifndef __NAN_HPP__
#define __NAN_HPP__

#include <literals/literal.hpp>

namespace jawe {
class Nan : public Literal {
public:
	Nan();
	~Nan();

	void print(std::ostream&) const override;
};
}
#endif // __NAN_HPP__

