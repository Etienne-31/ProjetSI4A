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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 25 "lex.y"
{ int nb; char* var; struct {int index_condition; int index_exit;}index_while;}
/* Line 1529 of yacc.c.  */
#line 117 "lex.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

