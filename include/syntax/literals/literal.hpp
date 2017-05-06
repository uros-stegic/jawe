#ifndef __LITERAL_HPP__
#define __LITERAL_HPP__

#include <expr.hpp>

namespace jawe {
class Literal : public Expr {
public:
	Literal();
	virtual ~Literal();
};
}

#endif // __LITERAL_HPP__

