#ifndef __NUMERIC_HPP__
#define __NUMERIC_HPP__

#include <literals/primitive_node.hpp>

namespace jawe {
class numeric_node : public primitive_node {
public:
	numeric_node(double);

	double get_value() const;

private:
	double m_value;
};
}
#endif // __NUMERIC_HPP__

