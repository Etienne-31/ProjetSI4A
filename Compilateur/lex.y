%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Symbol_table.h"
#include "asm_gestion.h"

void yyerror(const char *s);
int yylex(void);
symbol_table *table;
int scope = 0;
FILE* output_file;

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
    Type_specifier tMAIN tLPAR Parameter_list tRPAR Scope {
      free_table(table);
      print_table(table);
      print_asm_table();};

Scope:
   tLBRACE Corps tRBRACE;
Corps:
   Declarations Statement_list;
        
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
        Expression tADD Terme //{add_asm("ADD", $1, $1, $3);}
        |Expression tSUB Terme //{add_asm("SUB",$1,$1,$3);}
        |Terme
;

Terme:
        Terme tMUL Facteur  //{add_asm("MUL", $1, $1, $3);}
        |Terme tDIV Facteur  //{add_asm("DIV", $1, $1, $3);}
        |Facteur
;

Facteur:
        tNB { int addrtemp = add_temp_var(table);
               // affecter tnb a l'adresse de la variable temp 
              add_asm("AFC",addrtemp,$1);
              remove_last_temp_var(table);
            }
        |tID {int addr = get_adress(table,$1);
             int addrtemp = add_temp_var(table);
             //affecte le contenu de l'adresse  de Id dans une var temp
             add_asm("ASS",addrtemp,addr);
             }
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
   tID tASSIGN tNB  {add_symbol(table,$1,scope);
                     //int index = add_asm("AFC",index,$3);
                     print_table(table);}
   
   |tID tASSIGN tNB tCOMMA Declaration_const  {add_symbol(table,$1,scope);
                                               //int index = add_asm("AFC",index,$3);
                                               print_table(table);}
   ;     
   
Declaration_int:
   tID   {add_symbol(table,$1,scope);
         add_asm("AFC",$1,0);
          print_table(table);}
   
   | tID tASSIGN Expression {add_symbol(table,$1,scope);
                             //int index = add_asm("COP",index,$3);
                             print_table(table);}

   | tID tASSIGN Expression tCOMMA Declaration_int {add_symbol(table,$1,scope);
                                                   //int index = add_asm("COP",index,$3);
                                                   print_table(table);}

   | tID tCOMMA Declaration_int {add_symbol(table,$1,scope);
                                 print_table(table);};   


Selection_statement:
   tIF tLPAR Conditions tRPAR tLBRACE {scope++;} Corps tRBRACE {remove_symbols_by_scope(table,scope);
                                                                  print_table(table);}  Else_statement;
   
   
Else_statement:
   /*empty*/
   |tELSE tLBRACE Statement_list tRBRACE;
   
   
Iteration_statement:
   tWHILE tLPAR Conditions tRPAR tLBRACE Statement_list tRBRACE;
   
   
Return_statement:
   tRETURN Expression tSEMI
   | tRETURN tSEMI;
   
   
Print_statement:
   tPRINT tLPAR Expression tRPAR tSEMI;
   
   
Assignement_statement:
    tID tASSIGN Expression tSEMI  {//int index = add_asm("COP",index,$3);
                                    print_table(table);};


%%

void yyerror(const char *s) {
   fprintf(stderr, "Syntax error: %s\n", s);
}

int main(void) {
   
   printf("Ecrire le programme a tester : \n");
   table = init_symbol_table();
   init_asm_table();
   

   //yydebug=1;
   yyparse();
   //open_output_file("asmcodev1");
   //close_output_file();
   
   return 0;
}
