#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <string>
#include <literals/literal.hpp>

namespace jawe {
class String : public Literal {
public:
	String(std::string);
	~String();

	void print(std::ostream&) const override;

private:
	std::string m_string;
};
}
#endif // __STRING_HPP__

