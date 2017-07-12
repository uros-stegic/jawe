#ifndef __ABSTRACT_OBJECT_HPP__
#define __ABSTRACT_OBJECT_HPP__

#include <literals/literal.hpp>

namespace jawe {
class AbstractObject : public Literal {
public:
	using Literal::Literal;
	virtual ~AbstractObject();

	virtual AbstractObject* copy() = 0;
};
}

#endif // __ABSTRACT_OBJECT_HPP__

