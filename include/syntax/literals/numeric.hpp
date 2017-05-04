#ifndef __NUMERIC_HPP__
#define __NUMERIC_HPP__

#include <literals/literal.hpp>

namespace jawe {
class Numeric : public Literal {
public:
	Numeric(double);
	~Numeric();

	void print(std::ostream&) const override;
	double value() const;

private:
	double m_value;
};
}
#endif // __NUMERIC_HPP__

