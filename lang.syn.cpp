/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "language/lang.ypp" /* yacc.c:339  */

#include <string>
#include <memory>
#include <utility>
#include <map>
#include <syntax.hpp>
#include <utils/reader.hpp>
#include <utils/control.hpp>
#include <boost/algorithm/string.hpp>

#define YYDEBUG 1
#define YYERROR_VERBOSE 1

jawe::Command* program;
void *err_block;

void yyerror(const std::string&);
extern int yylex();

#line 86 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "lang.syn.hpp".  */
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
#line 21 "language/lang.ypp" /* yacc.c:355  */

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

#line 223 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 254 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  91
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1564

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  251

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   338

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      86,    89,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,     2,
       2,     2,     2,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,     2,    76,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      77,    78,    79,    82,    83,    84,    85,    87,    88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   116,   116,   118,   119,   121,   122,   124,   125,   126,
     127,   128,   129,   131,   132,   133,   134,   135,   136,   137,
     139,   149,   150,   151,   152,   153,   154,   156,   158,   161,
     163,   174,   176,   185,   186,   187,   188,   190,   192,   201,
     202,   203,   204,   205,   206,   207,   208,   210,   211,   212,
     213,   214,   215,   216,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   229,   230,   231,   233,   234,   235,
     236,   237,   238,   239,   241,   248,   250,   252,   260,   261,
     263,   265,   266,   267,   269,   270,   272,   273,   275,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   298,   299,   300,   302,   303,   304,   305,   306,
     307,   308,   310,   311,   313,   320,   321,   322,   324,   332,
     333,   334,   336,   338,   339,   341,   343,   344,   346,   347,
     349,   350,   352
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "delim_token", "id_token",
  "undefined_token", "null_token", "nan_token", "true_token",
  "false_token", "num_token", "string_token", "return_token",
  "break_token", "cont_token", "if_token", "else_token", "switch_token",
  "case_token", "while_token", "for_token", "do_token", "default_token",
  "assign_token", "ass_plus_token", "ass_minus_token", "ass_pow_token",
  "ass_mult_token", "ass_div_token", "ass_mod_token", "ass_sh_l_token",
  "ass_sh_r_token", "ass_sh_u_token", "ass_con_b_token", "ass_xor_b_token",
  "ass_dis_b_token", "log_or_token", "log_and_token", "bit_or_token",
  "bit_xor_token", "bit_and_token", "eq_token", "not_eq_token",
  "t_eq_token", "t_not_eq_token", "less_token", "less_eq_token",
  "great_token", "great_eq_token", "in_token", "instanceof_token",
  "bit_shift_l_token", "bit_shift_r_token", "bit_shift_u_token",
  "plus_token", "minus_token", "times_token", "divide_token", "mod_token",
  "power_token", "inc_token", "dec_token", "log_not_token",
  "bit_not_token", "delete_token", "void_token", "typeof_token",
  "new_token", "function_token", "const_token", "let_token", "var_token",
  "bracket_token", "bracket_closed", "dot_access_token", "'{'", "'}'",
  "no_else_token", "phony_lval", "comma_token", "'?'", "':'",
  "uplus_token", "uminus_token", "post_inc", "post_dec", "'('",
  "fn_call_token", "prec_parens_token", "')'", "$accept", "Program",
  "CodeBlock", "Command", "Undelimited", "Delimited", "NamedFun",
  "Declaration", "Cond", "While", "For", "DoWhile", "SwitchCase", "Cases",
  "Case", "Default", "Expr", "LValue", "ArgList", "ArgListFull",
  "ArgListNone", "Assign", "Literal", "Primitive", "IndexedObj",
  "ArrLiteral", "LiteralList", "ObjLiteral", "KVLiterals", "KVLiteral",
  "Key", "Lambda", "LambdaBody", "IDList", "IDListFull", "IDListEmpty", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   123,   125,   330,   331,   332,
      63,    58,   333,   334,   335,   336,    40,   337,   338,    41
};
# endif

#define YYPACT_NINF -60

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     612,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   711,
     -60,   -60,   -59,   -38,   -37,   -27,   612,   711,   711,   711,
     711,   711,   711,   711,   711,   711,   711,    25,   727,   799,
     815,   711,   229,   711,    64,   256,   -60,   -60,    65,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,  1238,   804,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,    -7,    50,  1238,   711,   711,
     711,   639,    61,   115,   115,   115,   115,   115,   115,   115,
     115,   115,    -9,    -5,    78,    21,  1238,    40,    41,    42,
      43,    44,  1238,   -13,     3,     4,   392,   -48,   -60,    53,
     866,   -60,   -60,   -60,   711,   711,   711,   711,   711,   711,
     711,   711,   711,   711,   711,   711,   711,   711,   711,   711,
     711,   711,   711,   711,   711,   711,   711,   711,   -60,   -60,
     711,   711,   711,   711,   711,   711,   711,   711,   711,   711,
     711,   711,   711,   711,   711,   711,   711,   -60,   -60,   920,
     974,  1028,   132,    51,    78,   -60,    47,    59,   -60,   -60,
     711,   -60,   -60,    50,   711,   -60,   111,  1287,  1335,  1382,
    1428,  1470,  1470,  1470,  1470,   -19,   -19,   -19,   -19,   -19,
     -19,  1478,  1478,  1478,   683,   683,    -3,    -3,    -3,    -3,
    1136,   -60,  1187,  1238,    52,    60,   -60,  1238,  1238,  1238,
    1238,  1238,  1238,  1238,  1238,  1238,  1238,  1238,  1238,  1238,
     612,    68,   612,   711,   711,    55,    70,   136,  1238,   -60,
    1238,   -60,   711,   -60,   711,   131,     8,   -60,   309,  1082,
      99,   419,   -60,  1238,  1238,   612,    67,    96,   -14,   -60,
     -60,   639,   -60,   612,   502,   102,   -60,    98,   612,   -60,
     -60,   -60,    91,   529,   -60,   612,   -60,   612,   -60,   -60,
     -60
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      19,    83,   105,   106,   107,   108,   109,   110,   111,     0,
      18,    17,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,   121,     0,     0,     2,     4,     6,     0,    11,
      14,     7,     8,     9,    15,    10,    13,    78,    80,    79,
     102,   103,   112,   113,   104,     0,   121,    16,     0,     0,
       0,    19,     0,    45,    46,    47,    48,    64,    67,    51,
      53,    52,    76,     0,   132,    83,     0,    80,    83,    80,
      83,    80,   116,     0,    83,   111,    19,     0,   120,     0,
       0,     1,     3,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    50,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,   123,     0,
       0,     0,     0,     0,   132,   131,     0,   128,   129,   114,
       0,    12,   118,     0,     0,    75,    66,    65,    69,    70,
      68,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    71,    72,    73,    39,    40,    41,    42,    43,    44,
       0,    82,     0,    87,     0,    85,    84,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      19,     0,    19,     0,     0,     0,     0,     0,   115,   119,
     122,    81,     0,    77,     0,    27,     0,    29,     0,     0,
       0,    19,   130,    74,    86,    19,     0,     0,     0,    35,
      36,    19,    31,    19,    19,     0,    28,     0,    19,    32,
      33,    34,     0,    19,   125,    19,    38,    19,    20,    37,
      30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -30,   -16,   -60,   -58,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -47,   -46,    -8,   -60,   -60,   -60,
     -60,   -23,   -60,   -36,   -60,   -60,   -60,   -60,   -60,    35,
     -60,   -60,   -60,    48,   -60,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,   228,   229,   230,    46,    47,   184,   185,
     186,    48,    49,    50,    51,    52,    83,    53,    87,    88,
      89,    54,   235,   146,   147,   148
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    57,    86,   142,   226,    77,    79,    81,   227,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    92,
      76,    76,    76,    82,   -21,    90,   226,    58,   152,    73,
     227,   153,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   -22,   -25,   -26,   -23,   -24,    59,    60,
     139,   140,   141,   120,   137,   121,   117,   118,   119,    61,
     149,   138,   239,   120,    91,   121,   150,   123,    93,   120,
      92,   121,     2,     3,     4,     5,     6,     7,     8,    74,
     143,   144,   145,   123,  -124,  -123,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     -21,    74,   180,   181,   182,   183,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   -22,
     -25,   -26,   -23,   -24,   154,   203,   206,   204,   207,   214,
     222,   213,   208,   216,   220,   221,   210,   225,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   242,   233,   118,   119,   238,   244,   245,
     247,   240,   241,   120,   215,   121,   217,   120,   209,   121,
     237,   234,   205,     0,     0,   218,   219,   123,     0,     0,
       0,   123,     0,   243,   223,     0,   224,     0,     0,   236,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,     0,   246,     0,     0,     0,     0,    92,     0,   249,
       0,   250,   -19,    84,     2,     3,     4,     5,     6,     7,
      85,     9,    10,    11,    12,     0,    13,     0,    14,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,   -19,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,     0,    14,    15,    16,     0,     0,
       0,     0,     0,    17,    18,     0,     0,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,    32,     0,     0,     0,     0,     0,
      17,    18,   231,     0,     0,    33,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,   121,     0,     0,     0,     0,     0,   122,
       0,     0,     0,     0,     0,   123,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
       0,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,    14,    15,
      16,     0,     0,     0,     0,     0,    17,    18,     0,     0,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,     0,    32,   151,     0,
       0,     0,     0,    17,    18,     0,     0,     0,    33,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,    32,  -127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
       0,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,    14,    15,
      16,     0,     0,     0,     0,     0,    17,    18,     0,     0,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,     0,    32,  -126,     0,
       0,     0,     0,    17,    18,     0,     0,     0,    33,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,     0,    32,   248,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
       0,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,     0,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,    17,    18,     0,     0,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,     0,    32,     0,     0,
       0,     0,     0,    17,    18,     0,     0,     0,    33,    19,
      20,    21,    22,    23,    24,    25,    26,    55,    28,    29,
      30,    31,     0,     0,    56,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     0,    33,     0,     0,     0,     0,
       0,    75,     2,     3,     4,     5,     6,     7,     8,   114,
     115,   116,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,     0,   121,     0,     0,
       0,     0,     0,     0,     0,    17,    18,     0,     0,   123,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    55,
       0,    17,    18,    31,     0,     0,    56,    19,    20,    21,
      22,    23,    24,    25,    26,    55,     0,    33,     0,    31,
       0,     0,    56,    78,     2,     3,     4,     5,     6,     7,
       8,     0,     0,    33,     0,     0,     0,     0,     0,    80,
       2,     3,     4,     5,     6,     7,     8,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,     0,     0,     0,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    55,     0,    17,
      18,    31,     0,     0,    56,    19,    20,    21,    22,    23,
      24,    25,    26,    55,     0,    33,     0,    31,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,     0,
     121,     0,     0,     0,     0,     0,   122,     0,     0,     0,
       0,     0,   123,     0,     0,   155,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,     0,   121,     0,     0,     0,     0,     0,
     122,     0,     0,     0,     0,     0,   123,     0,     0,   200,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,     0,   121,     0,
       0,     0,     0,     0,   122,     0,     0,     0,     0,     0,
     123,     0,     0,   201,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,     0,   121,     0,     0,     0,     0,     0,   122,     0,
       0,     0,     0,     0,   123,     0,     0,   202,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,     0,   121,     0,     0,     0,
       0,     0,   122,     0,     0,     0,     0,     0,   123,     0,
       0,   232,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,   211,
     121,     0,     0,     0,     0,     0,   122,     0,     0,     0,
       0,     0,   123,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
       0,   121,     0,     0,     0,     0,     0,   122,   212,     0,
       0,     0,     0,   123,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,     0,   121,     0,     0,     0,     0,     0,   122,     0,
       0,     0,     0,     0,   123,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
       0,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,     0,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,     0,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,     0,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   112,   113,   114,   115,   116,   117,   118,   119,
       0,     0,   120,     0,   121,     0,     0,     0,     0,     0,
     120,     0,   121,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   123
};

static const yytype_int16 yycheck[] =
{
      16,     9,    32,    61,    18,    28,    29,    30,    22,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    35,
      28,    29,    30,    31,     3,    33,    18,    86,    76,     4,
      22,    79,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,     3,     3,     3,     3,     3,    86,    86,
      58,    59,    60,    72,     4,    74,    59,    60,    61,    86,
      73,    11,    76,    72,     0,    74,    79,    86,     3,    72,
      86,    74,     5,     6,     7,     8,     9,    10,    11,    86,
      19,    86,     4,    86,    81,    81,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
      89,    86,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,    89,
      89,    89,    89,    89,    81,     3,    89,    86,    79,    79,
       4,    89,   150,    75,    89,    75,   154,    16,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   231,    75,    60,    61,    81,    76,    81,
      89,   228,   228,    72,   200,    74,   202,    72,   153,    74,
     226,   221,   144,    -1,    -1,   203,   204,    86,    -1,    -1,
      -1,    86,    -1,   233,   212,    -1,   214,    -1,    -1,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,    -1,
      -1,    -1,   238,    -1,    -1,    -1,    -1,   243,    -1,   245,
      -1,   247,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    -1,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      54,    55,     3,    -1,    -1,    86,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    86,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    75,    76,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    86,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    75,    76,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    86,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    86,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    75,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    86,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    54,    55,    72,    -1,    -1,    75,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    86,    -1,    72,
      -1,    -1,    75,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    54,
      55,    72,    -1,    -1,    75,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    86,    -1,    72,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    89,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    86,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    -1,    86,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    86,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    74,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    17,    19,    20,    21,    54,    55,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    75,    86,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   106,   107,   111,   112,
     113,   114,   115,   117,   121,    68,    75,   106,    86,    86,
      86,    86,    93,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,     4,    86,     4,   106,   111,     4,   111,
       4,   111,   106,   116,     4,    11,    92,   118,   119,   120,
     106,     0,    93,     3,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      72,    74,    80,    86,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     4,    11,   106,
     106,   106,    95,    19,    86,     4,   123,   124,   125,    73,
      79,    76,    76,    79,    81,    89,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   108,   109,   110,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
      89,    89,    89,     3,    86,   123,    89,    79,   106,   119,
     106,    73,    81,    89,    79,    93,    75,    93,   106,   106,
      89,    75,     4,   106,   106,    16,    18,    22,   103,   104,
     105,     3,    89,    75,    92,   122,    93,   113,    81,    76,
     104,   105,    95,    92,    76,    81,    93,    89,    76,    93,
      93
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    92,    92,    93,    93,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      96,    97,    97,    97,    97,    97,    97,    98,    98,    99,
     100,   101,   102,   103,   103,   103,   103,   104,   105,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   107,   107,   107,   108,   108,   109,   109,   110,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   115,   116,   116,   116,   117,   118,
     118,   118,   119,   120,   120,   121,   122,   122,   123,   123,
     124,   124,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     2,     1,     1,     0,
       8,     2,     2,     2,     2,     2,     2,     5,     7,     5,
       9,     6,     7,     2,     2,     1,     1,     4,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     5,     3,     2,     4,     1,     1,
       1,     4,     3,     1,     1,     1,     3,     1,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     0,     3,     3,
       1,     0,     3,     1,     1,     7,     1,     0,     1,     1,
       3,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 116 "language/lang.ypp" /* yacc.c:1646  */
    { program = (yyvsp[0].block);															}
#line 1887 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 118 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.block) = (yyvsp[-1].block); (yyval.block)->insert((yyvsp[0].command)); (yyvsp[0].command)->set_parent((yyvsp[-1].block));							}
#line 1893 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 119 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.block) = new jawe::CommandBlock((yyvsp[0].command)); (yyvsp[0].command)->set_parent((yyval.block));					}
#line 1899 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 121 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[-1].command);																}
#line 1905 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 122 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[0].command); 																}
#line 1911 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 124 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[0].command); 																}
#line 1917 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 125 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[0].command); 																}
#line 1923 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 126 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[0].command); 																}
#line 1929 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 127 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[0].command); 																}
#line 1935 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[0].command); 																}
#line 1941 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[-1].block); 																}
#line 1947 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 131 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[0].expr); 																}
#line 1953 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 132 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[0].command); 																}
#line 1959 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 133 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = (yyvsp[0].command); 																}
#line 1965 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 134 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::Return((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.command));						}
#line 1971 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 135 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::Continue(); 											}
#line 1977 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 136 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::Break();												}
#line 1983 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 137 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::Empty();												}
#line 1989 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 140 "language/lang.ypp" /* yacc.c:1646  */
    {
															auto fn = new jawe::Function(*(yyvsp[-4].string_vec), (yyvsp[-1].block));
															(yyvsp[-1].block)->set_parent(fn);
															(yyval.command) = new jawe::FunctionDeclaration(*(yyvsp[-6].string), fn);
															fn->set_parent((yyval.command));
															delete (yyvsp[-6].string);
															delete (yyvsp[-4].string_vec);
														}
#line 2002 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 149 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::ConstDeclaration(new jawe::Variable(*(yyvsp[0].string))); delete (yyvsp[0].string);	}
#line 2008 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::ConstDeclaration((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.command));				}
#line 2014 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 151 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::VarDeclaration(new jawe::Variable(*(yyvsp[0].string))); delete (yyvsp[0].string);	}
#line 2020 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 152 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::VarDeclaration((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.command));				}
#line 2026 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 153 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::LetDeclaration(new jawe::Variable(*(yyvsp[0].string))); delete (yyvsp[0].string);	}
#line 2032 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 154 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::LetDeclaration((yyvsp[0].expr)); err_block = &(yylsp[0]); (yyvsp[0].expr)->set_parent((yyval.command));	}
#line 2038 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 157 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::IfElse((yyvsp[-2].expr), (yyvsp[0].command)); (yyvsp[-2].expr)->set_parent((yyval.command)); (yyvsp[0].command)->set_parent((yyval.command));	}
#line 2044 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 159 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::IfElse((yyvsp[-4].expr), (yyvsp[-2].command), (yyvsp[0].command)); (yyvsp[-4].expr)->set_parent((yyval.command)); (yyvsp[-2].command)->set_parent((yyval.command)); (yyvsp[0].command)->set_parent((yyval.command)); }
#line 2050 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 161 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::While((yyvsp[-2].expr), (yyvsp[0].command)); (yyvsp[-2].expr)->set_parent((yyval.command)); (yyvsp[0].command)->set_parent((yyval.command));	}
#line 2056 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 167 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::For((yyvsp[-6].command), (yyvsp[-4].expr), (yyvsp[-2].command), (yyvsp[0].command));
			  												(yyvsp[-6].command)->set_parent((yyval.command));
			  												(yyvsp[-4].expr)->set_parent((yyval.command));
			  												(yyvsp[-2].command)->set_parent((yyval.command));
			  												(yyvsp[0].command)->set_parent((yyval.command));
			  											}
#line 2067 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 174 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::DoWhile((yyvsp[-4].command), (yyvsp[-1].expr)); (yyvsp[-4].command)->set_parent((yyval.command)); (yyvsp[-1].expr)->set_parent((yyval.command));	}
#line 2073 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 176 "language/lang.ypp" /* yacc.c:1646  */
    {
		   													(yyval.command) = new jawe::Switch((yyvsp[-4].expr), *(yyvsp[-1].comm_vec));
															(yyvsp[-4].expr)->set_parent((yyval.command));
															for(auto &&cs: *(yyvsp[-1].comm_vec)) {
																cs->set_parent((yyval.command));
															}
															delete (yyvsp[-1].comm_vec);
		   												}
#line 2086 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 185 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.comm_vec) = (yyvsp[-1].comm_vec); (yyval.comm_vec)->push_back((yyvsp[0].command)); 											}
#line 2092 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 186 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.comm_vec) = (yyvsp[-1].comm_vec); (yyval.comm_vec)->push_back((yyvsp[0].command)); 											}
#line 2098 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 187 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.comm_vec) = new std::vector<jawe::Command*>{(yyvsp[0].command)}; 							}
#line 2104 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 188 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.comm_vec) = new std::vector<jawe::Command*>{(yyvsp[0].command)}; 							}
#line 2110 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 190 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::Case(static_cast<jawe::Primitive*>((yyvsp[-2].expr)), (yyvsp[0].command)); (yyvsp[0].command)->set_parent((yyval.command)); }
#line 2116 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 192 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.command) = new jawe::Default((yyvsp[0].command)); (yyvsp[0].command)->set_parent((yyval.command));						}
#line 2122 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 201 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Plus((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2128 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 202 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Minus((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2134 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 203 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Times((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2140 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 204 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Divide((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));}
#line 2146 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 205 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Mod((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2152 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 206 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Power((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2158 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 207 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::UPlus((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.expr));							}
#line 2164 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 208 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::UMinus((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.expr));						}
#line 2170 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 210 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Increment((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.expr));						}
#line 2176 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 211 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Decrement((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.expr));						}
#line 2182 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 212 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::PostIncrement((yyvsp[-1].expr));	(yyvsp[-1].expr)->set_parent((yyval.expr));					}
#line 2188 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 213 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::PostDecrement((yyvsp[-1].expr));	(yyvsp[-1].expr)->set_parent((yyval.expr));					}
#line 2194 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 214 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Delete((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.expr)); 						}
#line 2200 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 215 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::TypeOf((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.expr));						}
#line 2206 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 216 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Void((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.expr));							}
#line 2212 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 218 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Equals((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));}
#line 2218 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 219 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::NotEquals((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2224 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 220 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::TypedEquals((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2230 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 221 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::TypedNotEquals((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));}
#line 2236 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 222 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::LessThen((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));		}
#line 2242 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 223 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::LessOrEquals((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2248 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 224 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::GreaterThen((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2254 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 225 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::GreaterOrEquals((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2260 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 226 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::In((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));			}
#line 2266 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 227 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::InstanceOf((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2272 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 229 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::LogicNot((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.expr));								}
#line 2278 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 230 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::LogicAnd((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));		}
#line 2284 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 231 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::LogicOr((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));		}
#line 2290 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 233 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::BitNot((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.expr));								}
#line 2296 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 234 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::BitAnd((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));		}
#line 2302 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 235 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::BitOr((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));			}
#line 2308 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 236 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::BitXor((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));		}
#line 2314 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 237 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::BitShiftLeft((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2320 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 238 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::BitShiftRight((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2326 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 239 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::BitShiftUnsigned((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	}
#line 2332 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 241 "language/lang.ypp" /* yacc.c:1646  */
    {
															(yyval.expr) = new jawe::TernaryConditional((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));
															(yyvsp[-4].expr)->set_parent((yyval.expr));
															(yyvsp[-2].expr)->set_parent((yyval.expr));
															(yyvsp[0].expr)->set_parent((yyval.expr));
														}
#line 2343 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 248 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr);																}
#line 2349 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 250 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::New((yyvsp[0].expr)); (yyvsp[0].expr)->set_parent((yyval.expr));							}
#line 2355 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 252 "language/lang.ypp" /* yacc.c:1646  */
    {
															(yyval.expr) = new jawe::FunctionCall((yyvsp[-3].expr), *(yyvsp[-1].expr_vec));
															(yyvsp[-3].expr)->set_parent((yyval.expr));
															for(auto&& arg: *(yyvsp[-1].expr_vec)) {
																arg->set_parent((yyval.expr));
															}
															delete (yyvsp[-1].expr_vec);
														}
#line 2368 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 260 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);																}
#line 2374 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 261 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); 																}
#line 2380 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 263 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);																}
#line 2386 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 265 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::ArrayAccess((yyvsp[-3].expr), (yyvsp[-1].expr)); (yyvsp[-3].expr)->set_parent((yyval.expr)); (yyvsp[-1].expr)->set_parent((yyval.expr)); }
#line 2392 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 266 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::DotAccess((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));   }
#line 2398 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 267 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Variable(*(yyvsp[0].string)); delete (yyvsp[0].string);								}
#line 2404 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 269 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr_vec) = (yyvsp[0].expr_vec);																}
#line 2410 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 270 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr_vec) = (yyvsp[0].expr_vec);																}
#line 2416 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 272 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr_vec) = (yyvsp[-2].expr_vec); (yyval.expr_vec)->push_back((yyvsp[0].expr));											}
#line 2422 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 273 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<jawe::Expr*>{(yyvsp[0].expr)};								}
#line 2428 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 275 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<jawe::Expr*>;									}
#line 2434 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 277 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Assign((yyvsp[-2].expr), (yyvsp[0].expr)); (yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));      }
#line 2440 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 278 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::AssignPlus((yyvsp[-2].expr), (yyvsp[0].expr));(yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	  }
#line 2446 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 279 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::AssignMinus((yyvsp[-2].expr), (yyvsp[0].expr));(yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));  }
#line 2452 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 280 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::AssignPow((yyvsp[-2].expr), (yyvsp[0].expr));(yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));    }
#line 2458 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 281 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::AssignMul((yyvsp[-2].expr), (yyvsp[0].expr));(yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	  }
#line 2464 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 282 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::AssignDiv((yyvsp[-2].expr), (yyvsp[0].expr));	(yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));   }
#line 2470 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 283 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::AssignMod((yyvsp[-2].expr), (yyvsp[0].expr));	(yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr));	  }
#line 2476 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 284 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::AssignShiftL((yyvsp[-2].expr), (yyvsp[0].expr));(yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr)); }
#line 2482 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 285 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::AssignShiftR((yyvsp[-2].expr), (yyvsp[0].expr));(yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr)); }
#line 2488 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 286 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::AssignShiftU((yyvsp[-2].expr), (yyvsp[0].expr));(yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr)); }
#line 2494 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 287 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::AssignBitCon((yyvsp[-2].expr), (yyvsp[0].expr));(yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr)); }
#line 2500 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 288 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::AssignBitXor((yyvsp[-2].expr), (yyvsp[0].expr));(yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr)); }
#line 2506 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 289 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::AssignBitDis((yyvsp[-2].expr), (yyvsp[0].expr));(yyvsp[-2].expr)->set_parent((yyval.expr)); (yyvsp[0].expr)->set_parent((yyval.expr)); }
#line 2512 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 298 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); 																}
#line 2518 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 299 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); 																}
#line 2524 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 300 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);																}
#line 2530 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 302 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Undefined();											}
#line 2536 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 303 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Null();												}
#line 2542 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 304 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Nan();													}
#line 2548 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 305 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::True();												}
#line 2554 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 306 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::False();												}
#line 2560 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 307 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Numeric((yyvsp[0].number));											}
#line 2566 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 308 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::String(*(yyvsp[0].string)); delete (yyvsp[0].string);								}
#line 2572 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 310 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); 																}
#line 2578 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 311 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); 																}
#line 2584 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 313 "language/lang.ypp" /* yacc.c:1646  */
    {
		   													(yyval.expr) = new jawe::Array(*(yyvsp[-1].expr_vec));
															for(auto&& lit: *(yyvsp[-1].expr_vec)) {
																lit->set_parent((yyval.expr));
															}
														}
#line 2595 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 320 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr_vec) = (yyvsp[-2].expr_vec); (yyval.expr_vec)->push_back((yyvsp[0].expr));											}
#line 2601 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 321 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<jawe::Expr*>{(yyvsp[0].expr)};								}
#line 2607 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 322 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<jawe::Expr*>();									}
#line 2613 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 324 "language/lang.ypp" /* yacc.c:1646  */
    {
		   													(yyval.expr) = new jawe::Object(*(yyvsp[-1].key_vals));
															for(auto&& kval : *(yyvsp[-1].key_vals)) {
																kval.second->set_parent((yyval.expr));
															}
															delete (yyvsp[-1].key_vals);
		   												}
#line 2625 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 332 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.key_vals) = (yyvsp[-2].key_vals); (*(yyval.key_vals))[(yyvsp[0].key_val)->first] = (yyvsp[0].key_val)->second; delete (yyvsp[0].key_val);					}
#line 2631 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 333 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.key_vals) = new std::map<std::string, jawe::Expr*>; (*(yyval.key_vals))[(yyvsp[0].key_val)->first] = (yyvsp[0].key_val)->second; delete (yyvsp[0].key_val); }
#line 2637 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 334 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.key_vals) = new std::map<std::string, jawe::Expr*>;							}
#line 2643 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 336 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.key_val) = new std::pair<std::string, jawe::Expr*>(*(yyvsp[-2].string), (yyvsp[0].expr)); delete (yyvsp[-2].string);		}
#line 2649 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 338 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); 																}
#line 2655 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 339 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); 																}
#line 2661 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 342 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.expr) = new jawe::Function(*(yyvsp[-4].string_vec), (yyvsp[-1].block)); delete (yyvsp[-4].string_vec); (yyvsp[-1].block)->set_parent((yyval.expr));		}
#line 2667 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 343 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.block) = (yyvsp[0].block);																}
#line 2673 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 344 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.block) = new jawe::CommandBlock();										}
#line 2679 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 346 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.string_vec) = (yyvsp[0].string_vec); 																}
#line 2685 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 347 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.string_vec) = (yyvsp[0].string_vec); 																}
#line 2691 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 349 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.string_vec) = (yyvsp[-2].string_vec); (yyval.string_vec)->push_back(*(yyvsp[0].string)); delete (yyvsp[0].string);								}
#line 2697 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 350 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.string_vec) = new std::vector<std::string>{*(yyvsp[0].string)}; delete (yyvsp[0].string);					}
#line 2703 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 352 "language/lang.ypp" /* yacc.c:1646  */
    { (yyval.string_vec) = new std::vector<std::string>;									}
#line 2709 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
    break;


#line 2713 "/home/branislava/Programming/jawe/lang.syn.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 356 "language/lang.ypp" /* yacc.c:1906  */


void yyerror(const std::string& msg) {
	std::string filename = jawe::Control::get().input_filename();
	int line = jawe::Reader::get_reader().get_line();
	int position = jawe::Reader::get_reader().get_position();
	std::string buff = jawe::Reader::get_reader().get_buffer();
	YYLTYPE* block = (YYLTYPE*)err_block;
	
	if( block ) {
		line = block->first_line + 1;
		position = block->first_column;
	}

	std::cerr	<< "[ERROR] "
				<< filename
				<< ":" << (line)
				<< ":" << (position) 
				<< ": " << msg
				<< std::endl;

	buff = jawe::Reader::get_reader().get_line(line-1);
	int old_len = buff.size();
	boost::trim(buff);
	int new_len = buff.size();
	std::cerr	<< std::string(4, ' ');
	std::cerr	<< buff << std::endl
				<< std::string(4 + position-3 - (old_len - new_len), ' ')
				<< "--^--" << std::endl;

	std::exit(EXIT_FAILURE);
}

