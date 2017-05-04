#ifndef __LITERAL_HPP__
#define __LITERAL_HPP__

#include <atom.hpp>

namespace jawe {
class Literal : public Atom {
public:
	using Atom::Atom;
	virtual ~Literal();
};
}
#endif // __LITERAL_HPP__

