#include <expr.hpp>
#include <map>
#include <string>

using namespace jawe;

Expr::Expr(const Priority& P)
	: Command(TExpr)
	, m_priority(P)
{}

Priority Expr::priority() const
{
	return m_priority;
}

std::ostream& operator<<(std::ostream& out, const jawe::Priority priority){
    static std::map<Priority, std::string> strings;
    if (strings.size() == 0){
#define INSERT_ELEMENT(p) strings[p] = #p
		INSERT_ELEMENT(TAssign);
		INSERT_ELEMENT(TTernaryConditional);
		INSERT_ELEMENT(TLogicOr);
		INSERT_ELEMENT(TLogicAnd);
		INSERT_ELEMENT(TBitOr);
		INSERT_ELEMENT(TBitXor);
		INSERT_ELEMENT(TBitAnd);
		INSERT_ELEMENT(TEquals);
		INSERT_ELEMENT(TNotEquals);
		INSERT_ELEMENT(TTypedEquals);
		INSERT_ELEMENT(TTypedNotEquals);
		INSERT_ELEMENT(TLessThen);
		INSERT_ELEMENT(TLessOrEquals);
		INSERT_ELEMENT(TGreaterThen);
		INSERT_ELEMENT(TGreaterOrEquals);
		INSERT_ELEMENT(TInstanceOf);
		INSERT_ELEMENT(TIn);
		INSERT_ELEMENT(TBitShiftLeft);
		INSERT_ELEMENT(TBitShiftRight);
		INSERT_ELEMENT(TBitShiftUnsigned);
		INSERT_ELEMENT(TPlus);
		INSERT_ELEMENT(TMinus);
		INSERT_ELEMENT(TTimes);
		INSERT_ELEMENT(TDivide);
		INSERT_ELEMENT(TMod);
		INSERT_ELEMENT(TPower);
		INSERT_ELEMENT(TBitNot);
		INSERT_ELEMENT(TLogicNot);
		INSERT_ELEMENT(TUPlus);
		INSERT_ELEMENT(TUMinus);
		INSERT_ELEMENT(TIncrement);
		INSERT_ELEMENT(TDecrement);
		INSERT_ELEMENT(TDelete);
		INSERT_ELEMENT(TVoid);
		INSERT_ELEMENT(TTypeOf);
		INSERT_ELEMENT(TPostIncrement);
		INSERT_ELEMENT(TPostDecrement);
		INSERT_ELEMENT(TFunctionCall);
		INSERT_ELEMENT(TNew);
		INSERT_ELEMENT(TDotAccess);
		INSERT_ELEMENT(TArrayAccess);
		INSERT_ELEMENT(TObject);
		INSERT_ELEMENT(TPrimitive);
		INSERT_ELEMENT(TVariable);
		INSERT_ELEMENT(TFunction);
		INSERT_ELEMENT(TArray);
#undef INSERT_ELEMENT
    }   

    return out << strings[priority];
}

