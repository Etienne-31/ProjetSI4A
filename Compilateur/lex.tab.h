/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tINT = 258,
     tVOID = 259,
     tCONST = 260,
     tIF = 261,
     tELSE = 262,
     tWHILE = 263,
     tMAIN = 264,
     tRETURN = 265,
     tPRINT = 266,
     tADD = 267,
     tSUB = 268,
     tMUL = 269,
     tDIV = 270,
     tLT = 271,
     tGT = 272,
     tNE = 273,
     tEQ = 274,
     tGE = 275,
     tLE = 276,
     tASSIGN = 277,
     tAND = 278,
     tOR = 279,
     tNOT = 280,
     tLBRACE = 281,
     tRBRACE = 282,
     tLPAR = 283,
     tRPAR = 284,
     tSEMI = 285,
     tCOMMA = 286,
     tNB = 287,
     tID = 288
   };
#endif
/* Tokens.  */
#define tINT 258
#define tVOID 259
#define tCONST 260
#define tIF 261
#define tELSE 262
#define tWHILE 263
#define tMAIN 264
#define tRETURN 265
#define tPRINT 266
#define tADD 267
#define tSUB 268
#define tMUL 269
#define tDIV 270
#define tLT 271
#define tGT 272
#define tNE 273
#define tEQ 274
#define tGE 275
#define tLE 276
#define tASSIGN 277
#define tAND 278
#define tOR 279
#define tNOT 280
#define tLBRACE 281
#define tRBRACE 282
#define tLPAR 283
#define tRPAR 284
#define tSEMI 285
#define tCOMMA 286
#define tNB 287
#define tID 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "lex.y"
{ int nb; char* var; }
/* Line 1529 of yacc.c.  */
#line 117 "lex.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

