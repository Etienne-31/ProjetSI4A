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
int index_global;
//Pour pouvoir imbriquer des ifs et whiles
int queue[100];

int index_queue = 0;
int returnaddr;
int indexret;



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
#line 24 "lex.y"
{ int nb; char* var; struct {int index_condition; int index_exit;}index_while;}
/* Line 193 of yacc.c.  */
#line 187 "lex.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 200 "lex.tab.c"

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

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
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    20,    21,    22,    34,
      37,    39,    41,    42,    44,    48,    51,    53,    55,    58,
      60,    62,    64,    66,    68,    74,    76,    80,    84,    88,
      92,    96,    98,   100,   102,   106,   110,   112,   115,   121,
     127,   133,   137,   141,   145,   147,   149,   151,   152,   154,
     156,   159,   163,   168,   172,   178,   180,   184,   190,   194,
     195,   196,   197,   209,   210,   211,   212,   219,   220,   221,
     222,   223,   235,   236,   240,   243,   249
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    36,    -1,    37,    -1,    36,    37,    -1,
      41,     6,    25,    42,    26,    23,    40,    70,    24,    -1,
      -1,    -1,    41,    33,    38,    25,    42,    26,    23,    40,
      70,    39,    24,    -1,    53,    44,    -1,     3,    -1,     4,
      -1,    -1,    43,    -1,    42,    28,    43,    -1,     3,    33,
      -1,     4,    -1,    45,    -1,    44,    45,    -1,    72,    -1,
      58,    -1,    46,    -1,    65,    -1,    71,    -1,    33,    25,
      47,    26,    27,    -1,    48,    -1,    48,    28,    48,    -1,
      48,     9,    48,    -1,    48,    10,    48,    -1,    48,    11,
      48,    -1,    48,    12,    48,    -1,    49,    -1,    29,    -1,
      33,    -1,    25,    48,    26,    -1,    50,    52,    51,    -1,
      51,    -1,    22,    51,    -1,    25,    48,    13,    48,    26,
      -1,    25,    48,    14,    48,    26,    -1,    25,    48,    16,
      48,    26,    -1,    48,    13,    48,    -1,    48,    14,    48,
      -1,    48,    16,    48,    -1,    48,    -1,    20,    -1,    21,
      -1,    -1,    54,    -1,    55,    -1,    54,    55,    -1,     3,
      57,    27,    -1,     5,     3,    56,    27,    -1,    33,    19,
      29,    -1,    33,    19,    29,    28,    56,    -1,    33,    -1,
      33,    19,    48,    -1,    33,    19,    48,    28,    57,    -1,
      33,    28,    57,    -1,    -1,    -1,    -1,    30,    25,    50,
      59,    26,    23,    60,    40,    61,    24,    62,    -1,    -1,
      -1,    -1,    31,    63,    23,    64,    44,    24,    -1,    -1,
      -1,    -1,    -1,    32,    25,    66,    50,    67,    26,    23,
      68,    44,    69,    24,    -1,    -1,     7,    48,    27,    -1,
       7,    27,    -1,     8,    25,    48,    26,    27,    -1,    33,
      19,    48,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    47,    48,    52,    61,    65,    60,    74,
      77,    78,    81,    83,    84,    88,    89,    93,    94,    98,
      99,   100,   101,   102,   106,   115,   116,   120,   130,   140,
     149,   157,   161,   168,   176,   180,   181,   182,   186,   195,
     204,   213,   222,   231,   240,   247,   248,   251,   253,   256,
     257,   260,   261,   264,   271,   280,   286,   293,   299,   308,
     312,   313,   307,   320,   323,   325,   322,   335,   338,   341,
     342,   334,   351,   353,   354,   358,   366
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
  "tWHILE", "tID", "$accept", "Program", "Function_list", "Function", "@1",
  "@2", "Corps", "Type_specifier", "Parameter_list",
  "Parameter_declaration", "Statement_list", "Statement", "Function_call",
  "Arguments", "Expression", "Facteur", "Conditions", "Condition",
  "Separator", "Declarations", "Declaration_list", "Declaration_statement",
  "Declaration_const", "Declaration_int", "Selection_statement", "@3",
  "@4", "@5", "Else_statement", "@6", "@7", "Iteration_statement", "@8",
  "@9", "@10", "@11", "Return_statement", "Print_statement",
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
       0,    34,    35,    36,    36,    37,    38,    39,    37,    40,
      41,    41,    42,    42,    42,    43,    43,    44,    44,    45,
      45,    45,    45,    45,    46,    47,    47,    48,    48,    48,
      48,    48,    49,    49,    49,    50,    50,    50,    51,    51,
      51,    51,    51,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    57,    57,    59,
      60,    61,    58,    62,    63,    64,    62,    66,    67,    68,
      69,    65,    70,    70,    70,    71,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     9,     0,     0,    11,     2,
       1,     1,     0,     1,     3,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     5,     1,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     3,     1,     2,     5,     5,
       5,     3,     3,     3,     1,     1,     1,     0,     1,     1,
       2,     3,     4,     3,     5,     1,     3,     5,     3,     0,
       0,     0,    11,     0,     0,     0,     6,     0,     0,     0,
       0,    11,     0,     3,     2,     5,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    11,     0,     2,     3,     0,     1,     4,     0,
       6,    12,     0,     0,    16,     0,    13,    12,    15,     0,
       0,     0,    47,    14,     0,     0,     0,    72,     0,    48,
      49,    47,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    17,    21,    20,    22,    23,    19,    50,    72,
       0,     0,    51,     0,     0,     0,    74,    32,    33,     0,
      31,     5,     0,     0,    67,     0,     0,    18,     7,    56,
      58,     0,    52,     0,     0,     0,     0,     0,    73,     0,
       0,     0,    44,    59,    36,     0,     0,     0,    25,     0,
       0,    53,    34,    27,    28,    29,    30,     0,    37,     0,
       0,     0,     0,    45,    46,     0,     0,    68,    76,     0,
       0,     8,    57,     0,    75,     0,     0,     0,    41,    42,
      43,    35,     0,     0,    24,    26,    54,     0,     0,     0,
      60,     0,    38,    39,    40,    47,    69,    61,     0,     0,
      70,    63,     0,    64,    62,    71,     0,    65,     0,     0,
      66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    89,    27,     6,    15,    16,
      41,    42,    43,    87,    82,    60,    83,    84,   105,    28,
      29,    30,    54,    33,    44,   106,   135,   139,   144,   146,
     148,    45,    85,   123,   138,   142,    36,    46,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -131
static const yytype_int16 yypact[] =
{
      35,  -131,  -131,     9,    35,  -131,    -3,  -131,  -131,   -12,
    -131,    97,     1,    -2,  -131,    38,  -131,    97,  -131,    36,
      97,    45,    92,  -131,    52,    32,    78,    72,    17,    92,
    -131,    92,   -14,    71,    69,    -6,    83,    79,   106,   110,
      21,    17,  -131,  -131,  -131,  -131,  -131,  -131,  -131,    72,
      -9,    32,  -131,   113,    98,    -9,  -131,  -131,  -131,    51,
    -131,  -131,    -9,   -18,  -131,    -9,    -9,  -131,  -131,    42,
    -131,   120,  -131,   100,    -9,    -9,    -9,    -9,  -131,   104,
      47,    -9,   134,   107,  -131,   -18,    76,   103,    46,   109,
      32,   127,  -131,  -131,  -131,  -131,  -131,   131,  -131,    80,
      -9,    -9,    -9,  -131,  -131,    47,   111,   107,  -131,   132,
      -9,  -131,  -131,    69,  -131,    -9,    -9,    -9,   142,   142,
     142,  -131,   137,   135,  -131,   142,  -131,   108,   112,   130,
    -131,   139,  -131,  -131,  -131,    92,  -131,  -131,    17,   133,
      17,   105,   140,  -131,  -131,  -131,   143,  -131,    17,     4,
    -131
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,   159,  -131,  -131,   -30,  -131,   148,   147,
    -130,   -41,  -131,  -131,   -33,  -131,    84,   -70,  -131,  -131,
    -131,   141,    55,   -45,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,   122,  -131,  -131
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      67,    49,    59,     9,    80,    50,    70,    81,   140,     7,
      98,    57,    37,    11,    51,    58,    55,    69,   149,    55,
      57,    56,    73,    57,    58,    37,    17,    58,   150,    79,
      10,    18,    86,    88,    38,   121,    39,    40,     1,     2,
      65,    93,    94,    95,    96,   112,    66,    38,    99,    39,
      40,    74,    75,    76,    77,    74,    75,    76,    77,    22,
      74,    75,    76,    77,    19,    32,    20,   118,   119,   120,
      90,    24,    81,    20,   110,    31,    57,   125,    78,    35,
      58,    34,   127,   128,   129,    74,    75,    76,    77,    74,
      75,    76,    77,   115,   116,    25,   117,    26,    52,    67,
      13,    14,    53,   108,    62,   137,    92,    61,    67,    74,
      75,    76,    77,    74,    75,    76,    77,    74,    75,    76,
      77,    74,    75,    76,    77,    72,    92,   103,   104,   109,
      97,    63,    71,   111,   132,    64,   143,   122,   133,    74,
      75,    76,    77,    74,    75,    76,    77,   100,   101,    91,
     102,    74,    75,    76,    77,   113,   134,   141,   114,   124,
     130,   131,   136,     8,   145,    21,   147,    23,   126,   107,
      48,    68
};

static const yytype_uint8 yycheck[] =
{
      41,    31,    35,     6,    22,    19,    51,    25,   138,     0,
      80,    29,     8,    25,    28,    33,    25,    50,   148,    25,
      29,    27,    55,    29,    33,     8,    25,    33,    24,    62,
      33,    33,    65,    66,    30,   105,    32,    33,     3,     4,
      19,    74,    75,    76,    77,    90,    25,    30,    81,    32,
      33,     9,    10,    11,    12,     9,    10,    11,    12,    23,
       9,    10,    11,    12,    26,    33,    28,   100,   101,   102,
      28,    26,    25,    28,    28,    23,    29,   110,    27,     7,
      33,     3,   115,   116,   117,     9,    10,    11,    12,     9,
      10,    11,    12,    13,    14,     3,    16,     5,    27,   140,
       3,     4,    33,    27,    25,   135,    26,    24,   149,     9,
      10,    11,    12,     9,    10,    11,    12,     9,    10,    11,
      12,     9,    10,    11,    12,    27,    26,    20,    21,    26,
      26,    25,    19,    24,    26,    25,    31,    26,    26,     9,
      10,    11,    12,     9,    10,    11,    12,    13,    14,    29,
      16,     9,    10,    11,    12,    28,    26,    24,    27,    27,
      23,    26,    23,     4,    24,    17,    23,    20,   113,    85,
      29,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    35,    36,    37,    41,     0,    37,     6,
      33,    25,    38,     3,     4,    42,    43,    25,    33,    26,
      28,    42,    23,    43,    26,     3,     5,    40,    53,    54,
      55,    23,    33,    57,     3,     7,    70,     8,    30,    32,
      33,    44,    45,    46,    58,    65,    71,    72,    55,    40,
      19,    28,    27,    33,    56,    25,    27,    29,    33,    48,
      49,    24,    25,    25,    25,    19,    25,    45,    70,    48,
      57,    19,    27,    48,     9,    10,    11,    12,    27,    48,
      22,    25,    48,    50,    51,    66,    48,    47,    48,    39,
      28,    29,    26,    48,    48,    48,    48,    26,    51,    48,
      13,    14,    16,    20,    21,    52,    59,    50,    27,    26,
      28,    24,    57,    28,    27,    13,    14,    16,    48,    48,
      48,    51,    26,    67,    27,    48,    56,    48,    48,    48,
      23,    26,    26,    26,    26,    60,    23,    40,    68,    61,
      44,    24,    69,    31,    62,    24,    63,    23,    64,    44,
      24
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
        case 5:
#line 53 "lex.y"
    {
      free_table(table);
      scope=0;
      print_table(table);
      print_asm_table();
   ;}
    break;

  case 6:
#line 61 "lex.y"
    {
      int addr =add_asm("NOP",0);
      add_function((yyvsp[(2) - (2)].var),addr);
   ;}
    break;

  case 7:
#line 65 "lex.y"
    {
      indexret = add_asm("BX",1,returnaddr);
   ;}
    break;

  case 8:
#line 68 "lex.y"
    {
      print_function_table();
   ;}
    break;

  case 24:
#line 107 "lex.y"
    {
      int addrfunc = find_function_asm_address((yyvsp[(1) - (5)].var));
      add_asm("BX",1,addrfunc);
      returnaddr = add_asm("NOP",0);
      modif_asm_inst(indexret,"BX",1,returnaddr);
   ;}
    break;

  case 27:
#line 121 "lex.y"
    { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("ADD",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);
         print_asm_table();
         
        ;}
    break;

  case 28:
#line 131 "lex.y"
    { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("SUB",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);
         
        ;}
    break;

  case 29:
#line 141 "lex.y"
    { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("MUL",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);

        ;}
    break;

  case 30:
#line 149 "lex.y"
    { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("DIV",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);
         
        ;}
    break;

  case 32:
#line 161 "lex.y"
    { int addrtemp = add_temp_var(table);
              //int addr_nb= get_adress($1);

             printf("addr temp NB = %d\n",addrtemp);
              // affecter tnb a l'adresse de la variable temp 
              add_asm("AFC",2,addrtemp,(yyvsp[(1) - (1)].nb));
            ;}
    break;

  case 33:
#line 168 "lex.y"
    {int addr = get_adress(table,(yyvsp[(1) - (1)].var));
            printf("address de %s est %d\n", (yyvsp[(1) - (1)].var),addr);
             int addrtemp = add_temp_var(table);
             printf("addr temp = %d\n",addrtemp);
             //affecte le contenu de l'adresse  de Id dans une var temp
             add_asm("COP",2,addrtemp,addr);
             (yyval.nb)=addrtemp;
             ;}
    break;

  case 34:
#line 176 "lex.y"
    {(yyval.nb)=(yyvsp[(2) - (3)].nb);;}
    break;

  case 38:
#line 187 "lex.y"
    {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("INF",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         (yyval.nb)=addr_next_to_last;
         print_asm_table();
      ;}
    break;

  case 39:
#line 196 "lex.y"
    {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("SUP",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         (yyval.nb)=addr_next_to_last;
         print_asm_table();
      ;}
    break;

  case 40:
#line 205 "lex.y"
    {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("EQU",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         (yyval.nb)=addr_next_to_last;
         print_asm_table();
      ;}
    break;

  case 41:
#line 214 "lex.y"
    {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("INF",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         (yyval.nb)=addr_next_to_last;
         print_asm_table();
      ;}
    break;

  case 42:
#line 223 "lex.y"
    {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("SUP",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         (yyval.nb)=addr_next_to_last;
         print_asm_table();
      ;}
    break;

  case 43:
#line 232 "lex.y"
    {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("EQU",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         (yyval.nb)=addr_next_to_last;
         print_asm_table();
      ;}
    break;

  case 44:
#line 241 "lex.y"
    {
      (yyval.nb)=get_last_index_ts(table);
   ;}
    break;

  case 53:
#line 265 "lex.y"
    {
      int index = add_symbol(table,(yyvsp[(1) - (3)].var),scope);
      add_asm("AFC",2,index,(yyvsp[(3) - (3)].nb));
      print_table(table);
   ;}
    break;

  case 54:
#line 272 "lex.y"
    {
      int index = add_symbol(table,(yyvsp[(1) - (5)].var),scope);
      add_asm("AFC",index,(yyvsp[(3) - (5)].nb));
      print_table(table);
   ;}
    break;

  case 55:
#line 281 "lex.y"
    {
      add_symbol(table,(yyvsp[(1) - (1)].var),scope);
      print_table(table);
   ;}
    break;

  case 56:
#line 287 "lex.y"
    {
      remove_last_temp_var(table);
      int addr = add_symbol(table,(yyvsp[(1) - (3)].var),scope);
      print_table(table);
   ;}
    break;

  case 57:
#line 294 "lex.y"
    {
      int addr = add_symbol(table,(yyvsp[(1) - (5)].var),scope);
      print_table(table);
   ;}
    break;

  case 58:
#line 300 "lex.y"
    {
      add_symbol(table,(yyvsp[(1) - (3)].var),scope);
      print_table(table);
   ;}
    break;

  case 59:
#line 308 "lex.y"
    {
      (yyvsp[(1) - (3)].nb) = add_asm("JMF",2,(yyvsp[(3) - (3)].nb),0);
      remove_last_temp_var(table);

   ;}
    break;

  case 60:
#line 312 "lex.y"
    {scope++; ;}
    break;

  case 61:
#line 313 "lex.y"
    { 
      modif_asm_inst((yyvsp[(1) - (8)].nb),"JMF",2,(yyvsp[(3) - (8)].nb),get_last_index()+1);
      remove_symbols_by_scope(table,scope);                                                                                             
      print_table(table);

   ;}
    break;

  case 62:
#line 318 "lex.y"
    {add_asm("NOP",0);;}
    break;

  case 64:
#line 323 "lex.y"
    {
      (yyvsp[(1) - (1)].nb) = add_asm("JMP",1,0);
   ;}
    break;

  case 65:
#line 325 "lex.y"
    {scope++;;}
    break;

  case 66:
#line 326 "lex.y"
    {
      modif_asm_inst((yyvsp[(1) - (6)].nb),"JMP",1,get_last_index());
      remove_symbols_by_scope(table,scope);
      print_table(table);
   ;}
    break;

  case 67:
#line 335 "lex.y"
    {
      (yyvsp[(1) - (2)].index_while).index_condition = get_last_index();
   ;}
    break;

  case 68:
#line 338 "lex.y"
    {
      (yyvsp[(1) - (4)].index_while).index_exit = add_asm("JMF",2,(yyvsp[(4) - (4)].nb),0);
      remove_last_temp_var(table);
   ;}
    break;

  case 69:
#line 341 "lex.y"
    {scope++;;}
    break;

  case 70:
#line 342 "lex.y"
    {
      modif_asm_inst((yyvsp[(1) - (9)].index_while).index_exit,"JMF",2,(yyvsp[(4) - (9)].nb),get_last_index()+1);
      add_asm("JMP",1,(yyvsp[(1) - (9)].index_while).index_condition);;}
    break;

  case 71:
#line 344 "lex.y"
    {
      remove_symbols_by_scope(table,scope);
      print_table(table);
   
   ;}
    break;

  case 75:
#line 359 "lex.y"
    {
      add_asm("PRI",1,(yyvsp[(3) - (5)].nb));
      remove_last_temp_var(table);
   ;}
    break;

  case 76:
#line 367 "lex.y"
    {
      int addr = get_adress(table,(yyvsp[(1) - (4)].var));
      int addr_last= get_last_index_ts(table);
      add_asm("COP",2,addr,addr_last);
      remove_last_temp_var(table);
      print_table(table);
   ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1888 "lex.tab.c"
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


#line 376 "lex.y"


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

