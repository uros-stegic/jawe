#ifndef __LITERAL_HPP__
#define __LITERAL_HPP__

#include <expr.hpp>

namespace jawe {
class Literal : public Expr {
public:
	Literal(Priority p);
	virtual ~Literal();

	virtual Literal* copy() = 0;
};
}

#endif // __LITERAL_HPP__

