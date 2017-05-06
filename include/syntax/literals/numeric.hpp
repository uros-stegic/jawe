#ifndef __NUMERIC_HPP__
#define __NUMERIC_HPP__

#include <literals/primitive.hpp>

namespace jawe {
class Numeric : public Primitive {
public:
	Numeric(double);
	~Numeric();

	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;
	double value() const;

private:
	double m_value;
};
}
#endif // __NUMERIC_HPP__

