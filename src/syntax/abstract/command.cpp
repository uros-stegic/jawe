#include <command.hpp>
#include <map>
#include <string>
#include <utils/control.hpp>
#include <sstream>

using namespace jawe;

Command::Command(CommandType type)
	: m_type(type)
	, m_parent(nullptr)
{}
CommandType Command::get_type() const
{
	return m_type;
}

void Command::set_parent(Command* command)
{
	m_parent = command;
}
Command* Command::get_parent() const
{
	return m_parent;
}

std::string Command::memory_address() const
{
	std::stringstream ss;
	if( Control::get().show_memory() ) {
		ss << "[" << this << ": from <" << get_parent() << ">]";
	}
	return ss.str();
}

std::ostream& operator<<(std::ostream& out, const jawe::CommandType type){
    static std::map<CommandType, std::string> strings;
    if (strings.size() == 0){
#define INSERT_ELEMENT(p) strings[p] = #p
		INSERT_ELEMENT(TEmpty);
		INSERT_ELEMENT(TCommandBlock);
		INSERT_ELEMENT(TIfElse);
		INSERT_ELEMENT(TWhile);
		INSERT_ELEMENT(TDoWhile);
		INSERT_ELEMENT(TFor);
		INSERT_ELEMENT(TSwitch);
		INSERT_ELEMENT(TCase);
		INSERT_ELEMENT(TDefault);
		INSERT_ELEMENT(TBreak);
		INSERT_ELEMENT(TContinue);
		INSERT_ELEMENT(TReturn);
		INSERT_ELEMENT(TVarDeclaration);
		INSERT_ELEMENT(TLetDeclaration);
		INSERT_ELEMENT(TConstDeclaration);
		INSERT_ELEMENT(TFunctionDeclaration);
		INSERT_ELEMENT(TExpr);
#undef INSERT_ELEMENT
    }   

    return out << strings[type];
}

