#ifndef __TRUE_HPP__
#define __TRUE_HPP__

#include <literals/literal.hpp>

namespace jawe {
class True : public Literal {
public:
	True();
	~True();

	void print(std::ostream&) const override;
	bool value() const;
};
}
#endif // __TRUE_HPP__

