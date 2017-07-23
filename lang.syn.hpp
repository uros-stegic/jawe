/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_HOME_BRANISLAVA_PROGRAMMING_JAWE_LANG_SYN_HPP_INCLUDED
# define YY_YY_HOME_BRANISLAVA_PROGRAMMING_JAWE_LANG_SYN_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    delim_token = 258,
    id_token = 259,
    undefined_token = 260,
    null_token = 261,
    nan_token = 262,
    true_token = 263,
    false_token = 264,
    num_token = 265,
    string_token = 266,
    return_token = 267,
    break_token = 268,
    cont_token = 269,
    if_token = 270,
    else_token = 271,
    switch_token = 272,
    case_token = 273,
    while_token = 274,
    for_token = 275,
    do_token = 276,
    default_token = 277,
    assign_token = 278,
    ass_plus_token = 279,
    ass_minus_token = 280,
    ass_pow_token = 281,
    ass_mult_token = 282,
    ass_div_token = 283,
    ass_mod_token = 284,
    ass_sh_l_token = 285,
    ass_sh_r_token = 286,
    ass_sh_u_token = 287,
    ass_con_b_token = 288,
    ass_xor_b_token = 289,
    ass_dis_b_token = 290,
    log_or_token = 291,
    log_and_token = 292,
    bit_or_token = 293,
    bit_xor_token = 294,
    bit_and_token = 295,
    eq_token = 296,
    not_eq_token = 297,
    t_eq_token = 298,
    t_not_eq_token = 299,
    less_token = 300,
    less_eq_token = 301,
    great_token = 302,
    great_eq_token = 303,
    in_token = 304,
    instanceof_token = 305,
    bit_shift_l_token = 306,
    bit_shift_r_token = 307,
    bit_shift_u_token = 308,
    plus_token = 309,
    minus_token = 310,
    times_token = 311,
    divide_token = 312,
    mod_token = 313,
    power_token = 314,
    inc_token = 315,
    dec_token = 316,
    log_not_token = 317,
    bit_not_token = 318,
    delete_token = 319,
    void_token = 320,
    typeof_token = 321,
    new_token = 322,
    function_token = 323,
    const_token = 324,
    let_token = 325,
    var_token = 326,
    bracket_token = 327,
    bracket_closed = 328,
    dot_access_token = 329,
    no_else_token = 330,
    phony_lval = 331,
    comma_token = 332,
    uplus_token = 333,
    uminus_token = 334,
    post_inc = 335,
    post_dec = 336,
    fn_call_token = 337,
    prec_parens_token = 338
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "language/lang.ypp" /* yacc.c:1909  */

	jawe::CommandBlock* block;
	jawe::Command* command;
	jawe::Expr* expr;
	double number;
	std::string* string;
	std::vector<jawe::Expr*>* expr_vec;
	std::vector<jawe::Command*> *comm_vec;
	std::vector<std::string> *string_vec;
	std::map<std::string, jawe::Expr*> *key_vals;
	std::pair<std::string, jawe::Expr*> *key_val;

#line 151 "/home/branislava/Programming/jawe/lang.syn.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_HOME_BRANISLAVA_PROGRAMMING_JAWE_LANG_SYN_HPP_INCLUDED  */
