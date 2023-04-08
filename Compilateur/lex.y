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
int index_global;

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
%type <nb> Conditions
%type <nb> Condition
%type <nb> Declaration_int
%type <nb> Terme
%type <nb> Facteur
%start Program

%%
Program: Function_list;


Function_list:
   Function 
   | Function_list Function;
   
   
Function:
    Type_specifier tMAIN tLPAR Parameter_list tRPAR  tLBRACE Corps tRBRACE {
      free_table(table);
      print_table(table);
      print_asm_table();};

  
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
        Expression tADD Terme {int temp = add_temp_var(table);
                              add_asm("ADD", 3, temp, $1, $3);
                              $$ = temp;
                              remove_last_temp_var(table);}
        |Expression tSUB Terme {int temp = add_temp_var(table);
                              add_asm("SUB", 3, temp, $1, $3);
                              $$ = temp;
                              remove_last_temp_var(table);}
        |Terme {$$=$1;}
;

Terme:
        Terme tMUL Facteur  {int temp = add_temp_var(table);
                              add_asm("MUL", 3, temp, $1, $3);
                              $$ = temp;
                              remove_last_temp_var(table);}
        |Terme tDIV Facteur {int temp = add_temp_var(table);
                              add_asm("DIV", 3, temp, $1, $3);
                              $$ = temp;
                              remove_last_temp_var(table);}
        |Facteur{$$=$1;}
;

Facteur:
        tNB { int addrtemp = add_temp_var(table);
              // affecter tnb a l'adresse de la variable temp 
              add_asm("AFC",2,addrtemp,$1);
              $$=addrtemp;
              remove_last_temp_var(table);
            }
        |tID {int addr = get_adress(table,$1);
             //int addrtemp = add_temp_var(table);
             //affecte le contenu de l'adresse  de Id dans une var temp
             //add_asm("ASS",2,addrtemp,addr);
             $$=addr;
             }
        |tLPAR Expression tRPAR {$$=$2;}
;

Conditions:
   Conditions Separator Condition
   |Condition
   |tNOT Condition
   ;
   
Condition:
   tLPAR Expression tLT Expression tRPAR {int addr = add_temp_var(table);
                                          add_asm("INF",3,addr,$2,$4);
                                          $$=addr;
                                          remove_last_temp_var(table);}
   | tLPAR Expression tGT Expression tRPAR {int addr = add_temp_var(table);
                                             add_asm("SUP",3,addr,$2,$4);
                                             $$=addr;
                                             remove_last_temp_var(table);}
   | tLPAR Expression tEQ Expression tRPAR {int addr = add_temp_var(table);
                                             add_asm("EQU",3,addr,$2,$4);
                                             $$=addr;
                                             remove_last_temp_var(table);}
   | Expression tLT Expression {int addr = add_temp_var(table);
                                 add_asm("INF",3,addr,$1,$3);
                                 $$=addr;
                                 remove_last_temp_var(table);}
   | Expression tGT Expression {int addr = add_temp_var(table);
                                 add_asm("SUP",3,addr,$1,$3);
                                 $$=addr;
                                 remove_last_temp_var(table);}
   | Expression tEQ Expression {int addr = add_temp_var(table);
                                 add_asm("EQU",3,addr,$1,$3);
                                 $$=addr;
                                 remove_last_temp_var(table);}
   | Expression{$$=$1;}
   ;
   
Separator:
   tAND
   |tOR;
   

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
   tID tASSIGN tNB  {int index = add_symbol(table,$1,scope);
                     add_asm("AFC",2,index,$3);
                     print_table(table);}
   
   |tID tASSIGN tNB tCOMMA Declaration_const  {int index = add_symbol(table,$1,scope);
                                               add_asm("AFC",index,$3);
                                               print_table(table);}
   ;     
   
Declaration_int:
   tID   {add_symbol(table,$1,scope);
          print_table(table);}
   
   | tID tASSIGN Expression {int addr = add_symbol(table,$1,scope);
                             add_asm("COP",2,addr,$3);
                             print_table(table);}

   | tID tASSIGN Expression tCOMMA Declaration_int {int addr = add_symbol(table,$1,scope);
                                                    add_asm("COP",2,index,$3);
                                                    print_table(table);}

   | tID tCOMMA Declaration_int {add_symbol(table,$1,scope);
                                 print_table(table);};   


Selection_statement:
   tIF tLPAR Conditions tRPAR tLBRACE {scope++;
                                       index_global = add_asm("JMF",2,$3,0);} Corps tRBRACE { modif_asm_inst(index_global,"JMF",2,$3,get_last_index()+1);
                                                                                                remove_symbols_by_scope(table,scope);
                                                                                                index_global =0;
                                                                                                print_table(table);}  Else_statement;
   
Else_statement:
   /*empty*/
   |tELSE {index_global = add_asm("JMP",1,0);} tLBRACE{scope++;} Statement_list tRBRACE{modif_asm_inst(index_global,"JMP",1,get_last_index());
                                                                                       remove_symbols_by_scope(table,scope);
                                                                                       index_global =0;
                                                                                       print_table(table);};
         
   
Iteration_statement:
   tWHILE tLPAR Conditions{index_global = add_asm("JMF",2,$3,0);} tRPAR tLBRACE{scope++;} Statement_list {add_asm("JMP",1,index_global);
                                                                                                            modif_asm_inst(index_global,"JMF",2,$3,get_last_index());
                                                                                                            } tRBRACE{remove_symbols_by_scope(table,scope);
                                                                                                                        index_global =0;
                                                                                                                        print_table(table);};
   
   
Return_statement:
   tRETURN Expression tSEMI
   | tRETURN tSEMI;
   
   
Print_statement:
   tPRINT tLPAR Expression tRPAR tSEMI {add_asm("PRI",1,$3);};
   
   
Assignement_statement:
    tID tASSIGN Expression tSEMI  {int addr = get_adress(table,$1);
                                    add_asm("COP",2,addr,$3);
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
   open_output_file("ASMCODE.asm");
   close_output_file();
   
   return 0;
}
