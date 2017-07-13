#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <iostream>
#include <utils/leak_checker.hpp>

namespace jawe {
enum CommandType {
	TEmpty,
	TCommandBlock,
	TIfElse,
	TWhile,
	TDoWhile,
	TFor,
	TSwitch,
	TCase,
	TDefault,
	TBreak,
	TContinue,
	TReturn,
	TVarDeclaration,
	TLetDeclaration,
	TConstDeclaration,
	TFunctionDeclaration,
	TExpr
};
class Command : public LeakChecker<Command> {
public:
	Command(CommandType);
	virtual ~Command() = default;

	virtual void print(std::ostream&) const = 0;
	virtual void dump_ast(std::ostream&, int = 0) const = 0;
	virtual Command* copy() = 0;

	CommandType get_type() const;
	void set_parent(Command*);
	Command* get_parent() const;

private:
	CommandType m_type;
	Command* m_parent;

	void dump(std::ostream&, int = 0) const;
};
}

std::ostream& operator<<(std::ostream&, const jawe::CommandType);

#endif // __COMMAND_HPP__

