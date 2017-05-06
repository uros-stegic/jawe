#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <string>
#include <literals/primitive.hpp>

namespace jawe {
class String : public Primitive {
public:
	String(std::string);
	~String();

	void print(std::ostream&) const override;
	void dump_ast(std::ostream&, int = 0) const override;

private:
	std::string m_string;
};
}
#endif // __STRING_HPP__

