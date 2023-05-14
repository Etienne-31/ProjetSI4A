/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tINT = 258,
     tVOID = 259,
     tCONST = 260,
     tMAIN = 261,
     tRETURN = 262,
     tPRINT = 263,
     tADD = 264,
     tSUB = 265,
     tMUL = 266,
     tDIV = 267,
     tLT = 268,
     tGT = 269,
     tNE = 270,
     tEQ = 271,
     tGE = 272,
     tLE = 273,
     tASSIGN = 274,
     tAND = 275,
     tOR = 276,
     tNOT = 277,
     tLBRACE = 278,
     tRBRACE = 279,
     tLPAR = 280,
     tRPAR = 281,
     tSEMI = 282,
     tCOMMA = 283,
     tNB = 284,
     tIF = 285,
     tELSE = 286,
     tWHILE = 287,
     tID = 288
   };
#endif
/* Tokens.  */
#define tINT 258
#define tVOID 259
#define tCONST 260
#define tMAIN 261
#define tRETURN 262
#define tPRINT 263
#define tADD 264
#define tSUB 265
#define tMUL 266
#define tDIV 267
#define tLT 268
#define tGT 269
#define tNE 270
#define tEQ 271
#define tGE 272
#define tLE 273
#define tASSIGN 274
#define tAND 275
#define tOR 276
#define tNOT 277
#define tLBRACE 278
#define tRBRACE 279
#define tLPAR 280
#define tRPAR 281
#define tSEMI 282
#define tCOMMA 283
#define tNB 284
#define tIF 285
#define tELSE 286
#define tWHILE 287
#define tID 288




/* Copy the first part of user declarations.  */
#line 1 "lex.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Symbol_table.h"
#include "asm_gestion.h"
#include "Function_table.h"

void yyerror(const char *s);
int yylex(void);
symbol_table *table;
int scope = 0;
FILE* output_file;
int addr_ret;
int queue[100];
int nbparam_decl;
int index_queue = 0;
int addr_main;
int addr_func;
int nbparam_call;
int decalage;
int index_jmp_main;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 25 "lex.y"
{ int nb; char* var; struct {int index_condition; int index_exit;}index_while;}
/* Line 193 of yacc.c.  */
#line 188 "lex.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 201 "lex.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    13,    24,    25,
      36,    39,    41,    43,    44,    46,    50,    53,    55,    57,
      60,    62,    64,    66,    68,    70,    75,    76,    78,    82,
      86,    90,    94,    98,   100,   102,   104,   108,   112,   114,
     117,   123,   129,   135,   139,   143,   147,   149,   151,   153,
     154,   156,   158,   161,   165,   170,   174,   180,   182,   186,
     187,   194,   198,   199,   200,   201,   213,   214,   215,   222,
     223,   224,   225,   226,   227,   239,   240,   244,   247,   253,
     258
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    -1,    36,    37,    -1,    38,    -1,    37,
      38,    -1,    -1,    42,     6,    39,    25,    43,    26,    23,
      41,    72,    24,    -1,    -1,    42,    33,    25,    43,    26,
      40,    23,    41,    72,    24,    -1,    54,    45,    -1,     3,
      -1,     4,    -1,    -1,    44,    -1,    43,    28,    44,    -1,
       3,    33,    -1,     4,    -1,    46,    -1,    45,    46,    -1,
      74,    -1,    60,    -1,    47,    -1,    67,    -1,    73,    -1,
      33,    25,    48,    26,    -1,    -1,    49,    -1,    49,    28,
      48,    -1,    49,     9,    49,    -1,    49,    10,    49,    -1,
      49,    11,    49,    -1,    49,    12,    49,    -1,    50,    -1,
      29,    -1,    33,    -1,    25,    49,    26,    -1,    51,    53,
      52,    -1,    52,    -1,    22,    52,    -1,    25,    49,    13,
      49,    26,    -1,    25,    49,    14,    49,    26,    -1,    25,
      49,    16,    49,    26,    -1,    49,    13,    49,    -1,    49,
      14,    49,    -1,    49,    16,    49,    -1,    49,    -1,    20,
      -1,    21,    -1,    -1,    55,    -1,    56,    -1,    55,    56,
      -1,     3,    58,    27,    -1,     5,     3,    57,    27,    -1,
      33,    19,    29,    -1,    33,    19,    29,    28,    57,    -1,
      33,    -1,    33,    19,    49,    -1,    -1,    33,    19,    49,
      59,    28,    58,    -1,    33,    28,    58,    -1,    -1,    -1,
      -1,    30,    25,    51,    61,    26,    23,    62,    41,    24,
      63,    64,    -1,    -1,    -1,    31,    65,    23,    66,    45,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    32,    25,    68,
      51,    69,    26,    23,    70,    45,    71,    24,    -1,    -1,
       7,    49,    27,    -1,     7,    27,    -1,     8,    25,    49,
      26,    27,    -1,    33,    19,    49,    27,    -1,    33,    19,
      47,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    46,    46,    46,    52,    53,    58,    57,    77,    76,
      94,    97,    98,   101,   103,   104,   108,   113,   117,   118,
     122,   123,   124,   125,   126,   130,   142,   144,   145,   149,
     159,   169,   178,   186,   190,   195,   201,   205,   206,   207,
     211,   220,   229,   237,   245,   253,   261,   268,   269,   272,
     274,   277,   278,   281,   282,   285,   291,   299,   304,   311,
     310,   318,   326,   330,   331,   325,   346,   348,   345,   355,
     360,   363,   366,   367,   359,   378,   380,   385,   389,   397,
     404
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tINT", "tVOID", "tCONST", "tMAIN",
  "tRETURN", "tPRINT", "tADD", "tSUB", "tMUL", "tDIV", "tLT", "tGT", "tNE",
  "tEQ", "tGE", "tLE", "tASSIGN", "tAND", "tOR", "tNOT", "tLBRACE",
  "tRBRACE", "tLPAR", "tRPAR", "tSEMI", "tCOMMA", "tNB", "tIF", "tELSE",
  "tWHILE", "tID", "$accept", "Program", "@1", "Function_list", "Function",
  "@2", "@3", "Corps", "Type_specifier", "Parameter_list",
  "Parameter_declaration", "Statement_list", "Statement", "Function_call",
  "Arguments", "Expression", "Facteur", "Conditions", "Condition",
  "Separator", "Declarations", "Declaration_list", "Declaration_statement",
  "Declaration_const", "Declaration_int", "@4", "Selection_statement",
  "@5", "@6", "@7", "Else_statement", "@8", "@9", "Iteration_statement",
  "@10", "@11", "@12", "@13", "Return_statement", "Print_statement",
  "Assignement_statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    36,    35,    37,    37,    39,    38,    40,    38,
      41,    42,    42,    43,    43,    43,    44,    44,    45,    45,
      46,    46,    46,    46,    46,    47,    48,    48,    48,    49,
      49,    49,    49,    49,    50,    50,    50,    51,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      58,    58,    61,    62,    63,    60,    65,    66,    64,    64,
      68,    69,    70,    71,    67,    72,    72,    72,    73,    74,
      74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     0,    10,     0,    10,
       2,     1,     1,     0,     1,     3,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     4,     0,     1,     3,     3,
       3,     3,     3,     1,     1,     1,     3,     3,     1,     2,
       5,     5,     5,     3,     3,     3,     1,     1,     1,     0,
       1,     1,     2,     3,     4,     3,     5,     1,     3,     0,
       6,     3,     0,     0,     0,    11,     0,     0,     6,     0,
       0,     0,     0,     0,    11,     0,     3,     2,     5,     4,
       4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,    11,    12,     3,     4,     0,     5,
       6,     0,     0,    13,    13,     0,    17,     0,    14,     0,
      16,     8,     0,     0,     0,    15,    49,    49,     0,     0,
      75,     0,    50,    51,    75,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    18,    22,    21,    23,    24,
      20,    52,     0,     0,     0,    53,     0,     0,     0,    77,
      34,    35,     0,    33,     7,     0,     0,    70,     0,    26,
      19,     9,    58,    61,     0,    54,     0,     0,     0,     0,
       0,    76,     0,     0,     0,    46,    62,    38,     0,    35,
       0,     0,     0,    27,     0,    55,    36,    29,    30,    31,
      32,     0,    39,     0,     0,     0,     0,    47,    48,     0,
       0,    71,    80,    79,    25,    26,     0,     0,    78,     0,
       0,     0,    43,    44,    45,    37,     0,     0,    28,    60,
      56,     0,     0,     0,    63,     0,    40,    41,    42,    49,
      72,     0,     0,    64,    73,    69,     0,    66,    65,    74,
       0,    67,     0,     0,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,    12,    24,    30,     8,    17,
      18,    44,    45,    46,    92,    85,    63,    86,    87,   109,
      31,    32,    33,    57,    36,    94,    47,   110,   139,   145,
     148,   150,   152,    48,    88,   127,   142,   146,    39,    49,
      50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -138
static const yytype_int16 yypact[] =
{
    -138,    13,    20,  -138,  -138,  -138,    20,  -138,    -2,  -138,
    -138,   -19,    10,    23,    23,    12,  -138,    72,  -138,   112,
    -138,  -138,    23,    43,    50,  -138,   153,   153,    34,    74,
      75,    17,   153,  -138,    75,   -12,    54,    59,    47,    78,
      83,    84,   101,    21,    17,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,   113,    98,    34,  -138,    80,   109,    98,  -138,
    -138,  -138,    44,  -138,  -138,    98,   100,  -138,    99,    98,
    -138,  -138,     0,  -138,   121,  -138,    52,    98,    98,    98,
      98,  -138,    85,   110,    98,   135,    31,  -138,   100,   116,
     115,    48,   131,     9,   132,   133,  -138,  -138,  -138,  -138,
    -138,   136,  -138,    77,    98,    98,    98,  -138,  -138,   110,
     138,    31,  -138,  -138,  -138,    98,    34,    59,  -138,    98,
      98,    98,   143,   143,   143,  -138,   139,   140,  -138,  -138,
    -138,    95,   104,   108,  -138,   142,  -138,  -138,  -138,   153,
    -138,   144,    17,  -138,    17,   128,   145,  -138,  -138,  -138,
     147,  -138,    17,     6,  -138
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,  -138,   161,  -138,  -138,   -27,  -138,   157,
     150,  -137,   -43,   105,    60,   -36,  -138,    86,   -75,  -138,
    -138,  -138,   146,    62,   -51,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,   148,  -138,
    -138
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -60
static const yytype_int16 yytable[] =
{
      34,    70,    62,    73,    10,   144,    13,    53,   102,    77,
      78,    79,    80,     3,    40,   153,    54,    72,    77,    78,
      79,    80,    76,     4,     5,    40,    15,    16,   -59,    82,
     154,    11,    91,    93,   125,    14,    41,   115,    42,    43,
      68,    97,    98,    99,   100,    20,    69,    41,   103,    42,
      43,   107,   108,    77,    78,    79,    80,    77,    78,    79,
      80,    77,    78,    79,    80,   129,    26,    35,   122,   123,
     124,    81,    58,    27,    59,   113,    60,    37,    96,    93,
      61,    55,    38,   131,   132,   133,    77,    78,    79,    80,
     119,   120,    56,   121,    77,    78,    79,    80,    21,    74,
      22,    70,    64,    96,    77,    78,    79,    80,    65,    66,
      70,   101,   141,    77,    78,    79,    80,    77,    78,    79,
      80,   136,    83,    58,    58,    84,    67,    60,    60,    60,
     137,    61,    89,    61,   138,    84,    75,    71,    23,    60,
      22,    69,   112,    61,    77,    78,    79,    80,   104,   105,
      95,   106,    77,    78,    79,    80,    28,   114,    29,   147,
     116,   117,   134,   118,   126,   140,   135,     9,   143,   149,
     151,    19,    25,    90,   111,   128,     0,     0,    51,   130,
       0,     0,    52
};

static const yytype_int16 yycheck[] =
{
      27,    44,    38,    54,     6,   142,    25,    19,    83,     9,
      10,    11,    12,     0,     8,   152,    28,    53,     9,    10,
      11,    12,    58,     3,     4,     8,     3,     4,    28,    65,
      24,    33,    68,    69,   109,    25,    30,    28,    32,    33,
      19,    77,    78,    79,    80,    33,    25,    30,    84,    32,
      33,    20,    21,     9,    10,    11,    12,     9,    10,    11,
      12,     9,    10,    11,    12,   116,    23,    33,   104,   105,
     106,    27,    25,    23,    27,    27,    29,     3,    26,   115,
      33,    27,     7,   119,   120,   121,     9,    10,    11,    12,
      13,    14,    33,    16,     9,    10,    11,    12,    26,    19,
      28,   144,    24,    26,     9,    10,    11,    12,    25,    25,
     153,    26,   139,     9,    10,    11,    12,     9,    10,    11,
      12,    26,    22,    25,    25,    25,    25,    29,    29,    29,
      26,    33,    33,    33,    26,    25,    27,    24,    26,    29,
      28,    25,    27,    33,     9,    10,    11,    12,    13,    14,
      29,    16,     9,    10,    11,    12,     3,    26,     5,    31,
      28,    28,    23,    27,    26,    23,    26,     6,    24,    24,
      23,    14,    22,    68,    88,   115,    -1,    -1,    32,   117,
      -1,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    36,     0,     3,     4,    37,    38,    42,    38,
       6,    33,    39,    25,    25,     3,     4,    43,    44,    43,
      33,    26,    28,    26,    40,    44,    23,    23,     3,     5,
      41,    54,    55,    56,    41,    33,    58,     3,     7,    72,
       8,    30,    32,    33,    45,    46,    47,    60,    67,    73,
      74,    56,    72,    19,    28,    27,    33,    57,    25,    27,
      29,    33,    49,    50,    24,    25,    25,    25,    19,    25,
      46,    24,    49,    58,    19,    27,    49,     9,    10,    11,
      12,    27,    49,    22,    25,    49,    51,    52,    68,    33,
      47,    49,    48,    49,    59,    29,    26,    49,    49,    49,
      49,    26,    52,    49,    13,    14,    16,    20,    21,    53,
      61,    51,    27,    27,    26,    28,    28,    28,    27,    13,
      14,    16,    49,    49,    49,    52,    26,    69,    48,    58,
      57,    49,    49,    49,    23,    26,    26,    26,    26,    62,
      23,    41,    70,    24,    45,    63,    71,    31,    64,    24,
      65,    23,    66,    45,    24
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 46 "lex.y"
    {
   index_jmp_main = add_asm("JMP",1,0);
;}
    break;

  case 6:
#line 58 "lex.y"
    {
      addr_main = get_last_index();
      modif_asm_inst(index_jmp_main,"JMP",1,addr_main);

      /*addr_main = get_last_index();
      for(int i; i>=0;i--){
         modif_asm_inst(queue[index_queue],"JMP",1,addr_main);
         index_queue--;
      }*/
    ;}
    break;

  case 7:
#line 69 "lex.y"
    {
      print_table(table);
      print_asm_table();
      free_table(table);
      scope=0;
   ;}
    break;

  case 8:
#line 77 "lex.y"
    {  
      /*queue[index_queue] =add_asm("JMP",1,addr_main);
      add_function($2,queue[index_queue],nbparam_decl);
      index_queue++;*/
      add_function((yyvsp[(2) - (5)].var), get_last_index(),nbparam_decl);
      decalage = get_last_index_ts(table);
      addr_ret = add_return_address(table,nbparam_decl);

   ;}
    break;

  case 9:
#line 86 "lex.y"
    {  
      nbparam_decl=0;
      print_table(table);
      free_table(table);
   ;}
    break;

  case 16:
#line 109 "lex.y"
    {
      add_symbol(table,(yyvsp[(2) - (2)].var),scope);
      nbparam_decl++;
   ;}
    break;

  case 25:
#line 131 "lex.y"
    {
      int addrfunc = find_function_asm_address((yyvsp[(1) - (4)].var));
      //add_asm("JMP",1,addrfunc);
      nbparam_call = get_function_params((yyvsp[(1) - (4)].var));
      
      add_asm("CALL",2,addrfunc,get_last_index_ts(table)-nbparam_call);
      //remove_last_temp_var(table);
      

   ;}
    break;

  case 29:
#line 150 "lex.y"
    { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("ADD",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);
         
         
        ;}
    break;

  case 30:
#line 160 "lex.y"
    { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("SUB",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);
         
        ;}
    break;

  case 31:
#line 170 "lex.y"
    { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("MUL",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);

        ;}
    break;

  case 32:
#line 178 "lex.y"
    { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("DIV",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);
         
        ;}
    break;

  case 34:
#line 190 "lex.y"
    { int addrtemp = add_temp_var(table);
              //int addr_nb= get_adress($1);
              // affecter tnb a l'adresse de la variable temp 
              add_asm("AFC",2,addrtemp,(yyvsp[(1) - (1)].nb));
            ;}
    break;

  case 35:
#line 195 "lex.y"
    {int addr = get_adress(table,(yyvsp[(1) - (1)].var));
             int addrtemp = add_temp_var(table);
             //affecte le contenu de l'adresse  de Id dans une var temp
             add_asm("COP",2,addrtemp,addr);
             (yyval.nb)=addrtemp;
             ;}
    break;

  case 36:
#line 201 "lex.y"
    {(yyval.nb)=(yyvsp[(2) - (3)].nb);;}
    break;

  case 40:
#line 212 "lex.y"
    {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("INF",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         (yyval.nb)=addr_next_to_last;
         
      ;}
    break;

  case 41:
#line 221 "lex.y"
    {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("SUP",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         (yyval.nb)=addr_next_to_last;
         
      ;}
    break;

  case 42:
#line 230 "lex.y"
    {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("EQU",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         (yyval.nb)=addr_next_to_last;
      ;}
    break;

  case 43:
#line 238 "lex.y"
    {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("INF",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         (yyval.nb)=addr_next_to_last;
      ;}
    break;

  case 44:
#line 246 "lex.y"
    {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("SUP",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         (yyval.nb)=addr_next_to_last;
      ;}
    break;

  case 45:
#line 254 "lex.y"
    {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("EQU",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         (yyval.nb)=addr_next_to_last;
      ;}
    break;

  case 46:
#line 262 "lex.y"
    {
      (yyval.nb)=get_last_index_ts(table);
   ;}
    break;

  case 55:
#line 286 "lex.y"
    {
      int index = add_symbol(table,(yyvsp[(1) - (3)].var),scope);
      add_asm("AFC",2,index,(yyvsp[(3) - (3)].nb));
   ;}
    break;

  case 56:
#line 292 "lex.y"
    {
      int index = add_symbol(table,(yyvsp[(1) - (5)].var),scope);
      add_asm("AFC",index,(yyvsp[(3) - (5)].nb));
   ;}
    break;

  case 57:
#line 300 "lex.y"
    {
      add_symbol(table,(yyvsp[(1) - (1)].var),scope);
   ;}
    break;

  case 58:
#line 305 "lex.y"
    {
      remove_last_temp_var(table);
      int addr = add_symbol(table,(yyvsp[(1) - (3)].var),scope);
   ;}
    break;

  case 59:
#line 311 "lex.y"
    {
      remove_last_temp_var(table);
      int addr = add_symbol(table,(yyvsp[(1) - (3)].var),scope);
   ;}
    break;

  case 61:
#line 319 "lex.y"
    {
      add_symbol(table,(yyvsp[(1) - (3)].var),scope);
   ;}
    break;

  case 62:
#line 326 "lex.y"
    {
      (yyvsp[(1) - (3)].nb) = add_asm("JMF",2,(yyvsp[(3) - (3)].nb),0);
      remove_last_temp_var(table);

   ;}
    break;

  case 63:
#line 330 "lex.y"
    {scope++;;}
    break;

  case 64:
#line 331 "lex.y"
    { 
      modif_asm_inst((yyvsp[(1) - (9)].nb),"JMF",2,(yyvsp[(3) - (9)].nb),get_last_index());
      remove_symbols_by_scope(table,scope);
      scope--; 
      (yyvsp[(2) - (9)].nb) = get_last_index();


   ;}
    break;

  case 65:
#line 338 "lex.y"
    {if ((yyvsp[(11) - (11)].nb) == 1) { 
         modif_asm_inst((yyvsp[(1) - (11)].nb),"JMF",2,(yyvsp[(3) - (11)].nb),(yyvsp[(2) - (11)].nb)+1);
      }else {
         modif_asm_inst((yyvsp[(1) - (11)].nb),"JMF",2,(yyvsp[(3) - (11)].nb),(yyvsp[(2) - (11)].nb));
      };}
    break;

  case 66:
#line 346 "lex.y"
    {
      (yyvsp[(1) - (1)].nb) = add_asm("JMP",1,0);
   ;}
    break;

  case 67:
#line 348 "lex.y"
    {scope++;;}
    break;

  case 68:
#line 349 "lex.y"
    {
      modif_asm_inst((yyvsp[(1) - (6)].nb),"JMP",1,get_last_index());
      remove_symbols_by_scope(table,scope);
      scope--;
      (yyval.nb)=1;
   ;}
    break;

  case 69:
#line 355 "lex.y"
    {(yyval.nb)=0;;}
    break;

  case 70:
#line 360 "lex.y"
    {
      (yyvsp[(1) - (2)].index_while).index_condition = get_last_index();
   ;}
    break;

  case 71:
#line 363 "lex.y"
    {
      (yyvsp[(1) - (4)].index_while).index_exit = add_asm("JMF",2,(yyvsp[(4) - (4)].nb),0);
      remove_last_temp_var(table);
   ;}
    break;

  case 72:
#line 366 "lex.y"
    {scope++;;}
    break;

  case 73:
#line 367 "lex.y"
    {
      add_asm("JMP",1,(yyvsp[(1) - (9)].index_while).index_condition);
      modif_asm_inst((yyvsp[(1) - (9)].index_while).index_exit,"JMF",2,(yyvsp[(4) - (9)].nb),get_last_index());
      ;}
    break;

  case 74:
#line 371 "lex.y"
    {
      remove_symbols_by_scope(table,scope);
      scope--;
   
   ;}
    break;

  case 76:
#line 381 "lex.y"
    {
      add_asm("BX",2,addr_ret,(yyvsp[(2) - (3)].nb));
      remove_last_temp_var(table);
   ;}
    break;

  case 78:
#line 390 "lex.y"
    {
      add_asm("PRI",1,(yyvsp[(3) - (5)].nb));
      remove_last_temp_var(table);
   ;}
    break;

  case 79:
#line 398 "lex.y"
    {
      int addr = get_adress(table,(yyvsp[(1) - (4)].var));
      int addr_last= get_last_index_ts(table);
      add_asm("COP",2,addr,addr_last);
      remove_last_temp_var(table);
   ;}
    break;

  case 80:
#line 405 "lex.y"
    {
      add_temp_var(table);
      int addr = get_adress(table,(yyvsp[(1) - (4)].var));
      int result = get_last_index_ts(table);
      int first_param = get_last_index_ts(table)- nbparam_call;
      add_asm("COP",2,first_param,result);
      remove_last_temp_var(table);
      add_asm("COP",2,addr,first_param);
      for(int i=0; i<nbparam_call;i++){remove_last_temp_var(table);}
      nbparam_call = 0;
   ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1953 "lex.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 418 "lex.y"


void yyerror(const char *s) {
   fprintf(stderr, "Syntax error: %s\n", s);
}

int main(void) {
   
   printf("Ecrire le programme a tester : \n");
   table = init_symbol_table();
   init_asm_table();
   //yydebug=1;
   yyparse();
   open_output_file("ASMCODE.asm");
   close_output_file();
   
   return 0;
}

