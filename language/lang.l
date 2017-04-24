%option noyywrap
%option nounput

%{
#include <iostream>
#include <string>
#include <cstdlib>

#include <lang.syn.hpp>

void llerror(const std::string& msg)
{
	std::cerr << "[Lexing Error]: " << msg << std::endl;
	std::exit(EXIT_FAILURE);
}
%}

INTEGER		[0-9]+
DECIMAL		[0-9]+\.[0-9]+

COND		[?:]

LOG_OR		"||"

LOG_AND		"&&"

BIT_OR		"|"

BIT_XOR		"^"

BIT_AND		"&"

EQ			"=="
NOT_EQ		"!="
T_EQ		"==="
T_NOT_EQ	"!=="

LESS		"<"
LESS_EQ		"<="
GREAT		">"
GREAT_EQ	">="

BIT_SHIFT_L	"<<"
BIT_SHIFT_R	">>"
BIT_SHIFT_U	">>>"

PLUS		"+"
MINUS		"-"

TIMES		"*"
DIVIDE		"/"
MOD			"%"

POW			"**"

INC			"++"
DEC			"--"
LOG_NOT		"!"
BIT_NOT		"~"

BLANK		[ \t\n]

%%

{DECIMAL}		{ return num_token;			}
{INTEGER}		{ return num_token;			}
{INC}			{ return inc_token;			}
{DEC}			{ return dec_token;			}
{POW}			{ return power_token;		}

{BIT_SHIFT_U}	{ return bit_shift_u_token; }
{BIT_SHIFT_L}	{ return bit_shift_l_token; }
{BIT_SHIFT_R}	{ return bit_shift_r_token;	}

{LESS}			{ return less_token;		}
{GREAT}			{ return great_token;		}
{LESS_EQ}		{ return less_eq_token;		}
{GREAT_EQ}		{ return great_eq_token;	}
{T_NOT_EQ}		{ return not_eq_token;		}
{T_EQ}			{ return t_eq_token;		}
{NOT_EQ}		{ return not_eq_token;		}
{EQ}			{ return eq_token;			}

{BIT_NOT}		{ return bit_not_token;		}
{BIT_AND}		{ return bit_and_token;		}
{BIT_OR}		{ return bit_or_token;		}
{BIT_XOR}		{ return bit_xor_token;		}

{LOG_NOT}		{ return log_not_token;		}
{LOG_AND}		{ return log_and_token;		}
{LOG_OR}		{ return log_or_token;		}

{PLUS}			{ return plus_token;		}
{MINUS}			{ return minus_token;		}
{TIMES}			{ return times_token;		}
{DIVIDE}		{ return divide_token;		}
{MOD}			{ return mod_token;			}

{COND}			{ return *yytext; }
{BLANK}+		{}
.				{ llerror(yytext); }
%%

