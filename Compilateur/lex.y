%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Symbol_table.h"

void yyerror(const char *s);
int yylex(void);
symbol_table *table;

%}

%union { int nb; char* var; }
%token tINT tVOID tCONST tIF tELSE tWHILE tMAIN tRETURN tPRINT
%token tADD tSUB tMUL tDIV tLT tGT tNE tEQ tGE tLE tASSIGN tAND tOR tNOT
%token tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA
%token <nb> tNB
%token <var> tID
%left tADD tSUB tMUL tDIV tEQ tNE
%nonassoc tLT tGT tLE tGE
%type <nb> Expression
%type <nb> Terme
%type <nb> Facteur
%start Program

%%
Program: Function_list;


Function_list:
   Function 
   | Function_list Function;
   
   
Function:
    Type_specifier tMAIN tLPAR Parameter_list tRPAR tLBRACE Declarations Statement_list tRBRACE {
      free_table(table);
      print_table(table);};

        
Type_specifier:
   tINT
   | tVOID;
   
   
Parameter_list:
    /*empty*/
   | Parameter_declaration
   | Parameter_list tCOMMA Parameter_declaration;
   
   
Parameter_declaration:
   tINT tID
   | tVOID;
   
   
Statement_list:
   Statement 
   | Statement_list Statement;
   
   
Statement:
    Assignement_statement
   | Selection_statement
   | Iteration_statement
   | Return_statement
   | Print_statement;
 
 
Expression:
        Expression tADD Terme
        |Expression tSUB Terme
        |Terme
;

Terme:
        Terme tMUL Facteur
        |Terme tDIV Facteur
        |Facteur
;

Facteur:
        tNB 
        |tID{int addr = get_adress(table,$1);
            int addrtemp = add_temp_var(table);
            printf("adresse de symbol ajoutée : %d depuis %d\n", addr, addrtemp);}
        |tLPAR Expression tRPAR
;

Conditions:
   Conditions Separator Condition
   |Condition
   |tNOT Condition
   ;
   
Condition:
   tLPAR Expression Cop Expression tRPAR
   | Expression Cop Expression
   |Expression
   ;
   
Separator:
   tAND
   |tOR;
   
   
Cop:
   tGT
   |tLT
   |tGE
   |tEQ
   |tNE
   |tLE
   ;

Declarations:
   /*empty*/
   |Declaration_list;

Declaration_list:
    Declaration_statement
   | Declaration_list  Declaration_statement 

Declaration_statement:
   tINT Declaration_int tSEMI
   |tCONST tINT Declaration_const tSEMI;

Declaration_const:
   tID tASSIGN tNB
   |tID tASSIGN tNB tCOMMA Declaration_const;     
   
Declaration_int:
   tID   {add_symbol(table,$1);
          print_table(table);}
   
   | tID tASSIGN Expression {add_symbol(table,$1);
                             print_table(table);}

   | tID tASSIGN Expression tCOMMA Declaration_int {add_symbol(table,$1);
                                                   print_table(table);}

   | tID tCOMMA Declaration_int {add_symbol(table,$1);
                                 print_table(table);};   


Selection_statement:
   tIF tLPAR Conditions tRPAR tLBRACE {increase_depth();} Statement_list tRBRACE { delete_same_scope_symbols(table); } Else_statement
   |tIF tLPAR Conditions tRPAR tLBRACE {increase_depth();} Statement_list tRBRACE { delete_same_scope_symbols(table); };
   
   
Else_statement:
   tELSE tLBRACE Statement_list tRBRACE;
   
   
Iteration_statement:
   tWHILE tLPAR Conditions tRPAR tLBRACE Statement_list tRBRACE;
   
   
Return_statement:
   tRETURN Expression tSEMI
   | tRETURN tSEMI;
   
   
Print_statement:
   tPRINT tLPAR Expression tRPAR tSEMI;
   
   
Assignement_statement:
    tID tASSIGN Expression tSEMI;

%%

void yyerror(const char *s) {
   fprintf(stderr, "Syntax error: %s\n", s);
}

int main(void) {
   printf("Ecrire le programme a tester : \n");
   table = init_symbol_table();
   //yydebug=1;
   yyparse();

   return 0;
}
