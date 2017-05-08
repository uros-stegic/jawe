#ifndef __EXPR_HPP__
#define __EXPR_HPP__

#include <command.hpp>

namespace jawe {
enum Priority {
	TAssign,
	TTernaryConditional,
	TLogicOr,
	TLogicAnd,
	TBitOr,
	TBitXor,
	TBitAnd,
	TEquals, TNotEquals, TTypedEquals, TTypedNotEquals,
	TLessThen, TLessOrEquals, TGreaterThen, TGreaterOrEquals, TInstanceOf, TIn,
	TBitShiftLeft, TBitShiftRight, TBitShiftUnsigned,
	TPlus, TMinus,
	TTimes, TDivide, TMod,
	TPower,
	TBitNot, TLogicNot, TUPlus, TUMinus, TIncrement, TDecrement, TDelete, TVoid, TTypeOf,
	TPostIncrement, TPostDecrement,
	TFunctionCall,
	TNew,
	TDotAccess, TArrayAccess,
	TLiteral
};

class Expr : public Command {
public:
	Expr(const Priority&);
	Priority priority() const;

private:
	Priority m_priority;
};
}

#endif // __EXPR_HPP__

