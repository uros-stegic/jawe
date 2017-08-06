#ifndef __TERNARY_OPERATOR_HPP__
#define __TERNARY_OPERATOR_HPP__

#include <operators/operator_node.hpp>
#include <shared_node.hpp>

namespace jawe {
class ternary_operator_node : public operator_node {
public:
	ternary_operator_node(const shared_node&, const shared_node&, const shared_node&, std::string, std::string);

	shared_node get_first_operand() const;
	shared_node get_second_operand() const;
	shared_node get_third_operand() const;
	std::string get_symbol2() const;
private:
	shared_node m_first, m_second, m_third;
	std::string m_symbol2;
};
}
#endif // __TERNARY_OPERATOR_HPP__
