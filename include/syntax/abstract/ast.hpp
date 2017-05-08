#ifndef __AST_HPP__
#define __AST_HPP__

#include <iostream>
#include <utils/mem_leak.hpp>

namespace jawe {
class Ast : public LeakChecker<Ast> {
public:
	virtual ~Ast();
	virtual void print(std::ostream&) const = 0;
	virtual void dump_ast(std::ostream&, int = 0) const = 0;
};
}

#endif // __AST_HPP__

