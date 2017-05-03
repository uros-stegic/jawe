#ifndef __ATOM_HPP__
#define __ATOM_HPP__

#include <expr.hpp>

namespace jawe {
class Atom : public Expr {
public:
	Atom();
	virtual ~Atom();
};
}

#endif // __ATOM_HPP__

