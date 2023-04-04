
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.tab.h"

%}
%option noyywrap
%option noinput
%option nounput
%%


"int" { return tINT; }
"void" { return tVOID; }
"const" { return tCONST; }
"if" { return tIF;}
"else" { return tELSE; }
"while" { return tWHILE; }
"main" { return tMAIN; }
"return" { return tRETURN; }
"print" { return tPRINT; }
[a-zA-Z]([a-z]|[A-Z]|[0-9]|_)* { 
	yylval.var=(char*)malloc(sizeof(char*));
	strcpy(yylval.var,yytext);
	return tID; 
	}
[0-9]+(\.[0-9]*)?([Ee][+-]?[0-9]+)? {
	  yylval.nb = atof(yytext);
	  return tNB;
	}
\/\/.* { /* ignore single-line comments */ }
\/\*([^*]|\*[^/])*\*\/ { /* ignore multi-line comments */ }
"+" { return tADD; }
"-" { return tSUB; }
"*" { return tMUL; }
"/" { return tDIV; }
"<" { return tLT; }
">" { return tGT; }
"!=" { return tNE; }
"==" { return tEQ; }
">=" { return tGE; }
"<=" { return tLE; }
"=" { return tASSIGN; }
"&&" { return tAND; }
"||" { return tOR; }
"!" { return tNOT; }
"{" { return tLBRACE; }
"}" { return tRBRACE; }
"(" { return tLPAR; }
")" { return tRPAR; }
";" { return tSEMI; }
"," { return tCOMMA; }
[ \t\r\n] { /* ignore whitespace */ }
. { printf("tERROR\n"); }



