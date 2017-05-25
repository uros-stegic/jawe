%option noyywrap
%option nounput

%x blk_comment
%x ln_comment

%{
#include <iostream>
#include <string>
#include <cstdlib>
#include <memory>
#include <utility>
#include <map>
#include <utils/reader.hpp>

#include <syntax.hpp>
#include <lang.syn.hpp>

#define YY_INPUT(buf,result,max_size) \
	result = jawe::Reader::get_reader().read(buf);

void llerror(const std::string& msg)
{
	std::cerr << "[ERROR]: Unrecognized token <" << msg << ">" << std::endl;
	std::exit(EXIT_FAILURE);
}
%}


INTEGER		[0-9]+
DECIMAL		[0-9]+\.[0-9]+

ASSIGN		"="
ASS_PLUS	"+="
ASS_MINUS	"-="
ASS_POW		"**="
ASS_MULT	"*="
ASS_DIV		"/="
ASS_MOD		"%="
ASS_SH_L	"<<="
ASS_SH_R	">>="
ASS_SH_U	">>>="
ASS_CON_B	"&="
ASS_XOR_B	"^="
ASS_DIS_B	"|="

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
IN			"in"
INSTANCE	"instanceof"

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
DELETE		"delete"
VOID		"void"
TYPEOF		"typeof"

BLANK		[ \t\n]
DELIM		[;]
SEPARATOR	[:]
COMMA		","

PARENS		[(){}]

UNDEF		"undefined"
NULL		"null"
TRUE		"true"
FALSE		"false"
NAN			"NaN"
STRING		(\"[^\"]*\")|('[^']*')

RETURN		"return"
BREAK		"break"
CONT		"continue"

IF			"if"
ELSE		"else"
SWITCH		"switch"
CASE		"case"
WHILE		"while"
FOR			"for"
DO			"do"
DEFAULT		"default"

NEW			"new"

FUNCTION	"function"
CONST		"const"
VAR			"var"
LET			"let"

ID			[$_a-zA-Z][$_a-zA-Z0-9]*
DOT_ACCESS	"."
BRK_OACCESS	"["
BRK_CACCESS	"]"

%%

^{BLANK}\n			{}

"//"				{ BEGIN(ln_comment); 		}
<ln_comment>[^\n]* 	{}
<ln_comment>\n		{ BEGIN(INITIAL);			}

"/*"				{ BEGIN(blk_comment);		}
<blk_comment>[^*]*	{}
<blk_comment>"*/"	{ BEGIN(INITIAL);			}

{RETURN}			{ return return_token;		}
{BREAK}				{ return break_token;		}
{CONT}				{ return cont_token;		}

{IF}				{ return if_token;			}
{ELSE}				{ return else_token;		}
{SWITCH}			{ return switch_token;		}
{CASE}				{ return case_token;		}
{WHILE}				{ return while_token;		}
{FOR}				{ return for_token;			}
{DO}				{ return do_token;			}
{DEFAULT}			{ return default_token;		}

{NEW}				{ return new_token;			}
{DOT_ACCESS}		{ return dot_access_token;	}
{BRK_OACCESS}		{ return bracket_token;		}
{BRK_CACCESS}		{ return bracket_closed;	}

{FUNCTION}			{ return function_token;	}

{CONST}				{ return const_token;		}
{VAR}				{ return var_token;			}
{LET}				{ return let_token;			}

{COMMA}				{ return comma_token;		}
{DELIM}				{ return delim_token;		}
{SEPARATOR}			{ return *yytext;			}

{DECIMAL}			{ yylval.number = std::atof(yytext); return num_token;			}
{INTEGER}			{ yylval.number = std::atoi(yytext); return num_token;			}
{UNDEF}				{ return undefined_token;	}
{NULL}				{ return null_token;		}
{TRUE}				{ return true_token;		}
{FALSE}				{ return false_token;		}
{STRING}			{ auto tmp = std::string(yytext); yylval.string = new std::string(tmp.substr(1, tmp.size()-2)); return string_token; }
{NAN}				{ return nan_token;			}
   
{ASS_POW}			{ return ass_pow_token;		}
{ASS_PLUS}			{ return ass_plus_token;	}
{ASS_MINUS}			{ return ass_minus_token;	}
{ASS_MULT}			{ return ass_mult_token;	}
{ASS_DIV}			{ return ass_div_token;		}
{ASS_MOD}			{ return ass_mod_token;		}
{ASS_SH_L}			{ return ass_sh_l_token;	}
{ASS_SH_R}			{ return ass_sh_r_token;	}
{ASS_SH_U}			{ return ass_sh_u_token;	}
{ASS_CON_B}			{ return ass_con_b_token;	}
{ASS_DIS_B}			{ return ass_dis_b_token;	}
{ASS_XOR_B}			{ return ass_xor_b_token;	}

{DELETE}			{ return delete_token;		}
{VOID}				{ return void_token;		}
{TYPEOF}			{ return typeof_token;		}
	
{INC}				{ return inc_token;			}
{DEC}				{ return dec_token;			}
{POW}				{ return power_token;		}

{BIT_SHIFT_U}		{ return bit_shift_u_token; }
{BIT_SHIFT_L}		{ return bit_shift_l_token; }
{BIT_SHIFT_R}		{ return bit_shift_r_token;	}

{LESS}				{ return less_token;		}
{GREAT}				{ return great_token;		}
{LESS_EQ}			{ return less_eq_token;		}
{GREAT_EQ}			{ return great_eq_token;	}
{INSTANCE}			{ return instanceof_token;	}
{IN}				{ return in_token;			}
{T_NOT_EQ}			{ return not_eq_token;		}
{T_EQ}				{ return t_eq_token;		}
{NOT_EQ}			{ return not_eq_token;		}
{EQ}				{ return eq_token;			}
	
{BIT_NOT}			{ return bit_not_token;		}
{BIT_AND}			{ return bit_and_token;		}
{BIT_OR}			{ return bit_or_token;		}
{BIT_XOR}			{ return bit_xor_token;		}

{LOG_NOT}			{ return log_not_token;		}
{LOG_AND}			{ return log_and_token;		}
{LOG_OR}			{ return log_or_token;		}
	
{PLUS}				{ return plus_token;		}
{MINUS}				{ return minus_token;		}
{TIMES}				{ return times_token;		}
{DIVIDE}			{ return divide_token;		}
{MOD}				{ return mod_token;			}

{ASSIGN}			{ return assign_token;		}

{COND}				{ return *yytext; 			}
{PARENS}			{ return *yytext; 			}

{ID}				{ yylval.string = new std::string(yytext); return id_token;	}
	
{BLANK}+			{}
.					{ llerror(yytext); }
%%


