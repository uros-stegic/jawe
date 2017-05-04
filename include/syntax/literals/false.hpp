#ifndef __FALSE_HPP__
#define __FALSE_HPP__

#include <literals/literal.hpp>

namespace jawe {
class False : public Literal {
public:
	False();
	~False();

	void print(std::ostream&) const override;
	bool value() const;
};
}
#endif // __FALSE_HPP__

