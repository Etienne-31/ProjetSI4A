%{
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

%}

%union { int nb; char* var; struct {int index_condition; int index_exit;}index_while;}
%token tINT tVOID tCONST tMAIN tRETURN tPRINT
%token tADD tSUB tMUL tDIV tLT tGT tNE tEQ tGE tLE tASSIGN tAND tOR tNOT
%token tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA
%token <nb> tNB
%token <nb> tIF
%token <nb> tELSE
%token <index_while> tWHILE
%token <var> tID
%left tADD tSUB tMUL tDIV tEQ tNE
%nonassoc tLT tGT tLE tGE
%type <nb> Expression
%type <nb> Conditions
%type <nb> Condition
%type <nb> Declaration_int
%type <nb> Facteur
%start Program

%%
Program: Function_list;


Function_list:
   Function 
   | Function_list Function;
   
   
Function:
    Type_specifier tMAIN tLPAR Parameter_list tRPAR  tLBRACE Corps Return_statement tRBRACE 
    {
      free_table(table);
      scope=0;
      print_table(table);
      print_asm_table();
   }

   | Type_specifier tID 
   {
      int addr =add_asm("NOP",0);
      add_function($2,addr);
   } tLPAR Parameter_list tRPAR tLBRACE Corps Return_statement
   {
      indexret = add_asm("BX",1,returnaddr);
   } tRBRACE 
   {
      print_function_table();
   };

  
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
   | Function_call
   | Iteration_statement
   | Print_statement;
 

Function_call:
   tID tLPAR Arguments tRPAR tSEMI
   {
      int addrfunc = find_function_asm_address($1);
      add_asm("BX",1,addrfunc);
      returnaddr = add_asm("NOP",0);
      modif_asm_inst(indexret,"BX",1,returnaddr);
   };

Arguments:
   Expression
   | Expression tCOMMA Expression;


Expression:
        Expression tADD Expression 
        { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("ADD",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);
         print_asm_table();
         
        }
        |Expression tSUB Expression 
        { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("SUB",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);
         
        }

        |Expression tMUL Expression
        { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("MUL",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);

        }  
        |Expression tDIV Expression { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("DIV",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);
         
        }
        |Facteur;
;

Facteur:
        tNB { int addrtemp = add_temp_var(table);
              //int addr_nb= get_adress($1);

             printf("addr temp NB = %d\n",addrtemp);
              // affecter tnb a l'adresse de la variable temp 
              add_asm("AFC",2,addrtemp,$1);
            }
        |tID {int addr = get_adress(table,$1);
            printf("address de %s est %d\n", $1,addr);
             int addrtemp = add_temp_var(table);
             printf("addr temp = %d\n",addrtemp);
             //affecte le contenu de l'adresse  de Id dans une var temp
             add_asm("COP",2,addrtemp,addr);
             $$=addrtemp;
             }
        |tLPAR Expression tRPAR {$$=$2;}
;

Conditions:
   Conditions Separator Condition
   |Condition
   |tNOT Condition
   ;
   
Condition:
   tLPAR Expression tLT Expression tRPAR 
      {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("INF",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         $$=addr_next_to_last;
         print_asm_table();
      }
   | tLPAR Expression tGT Expression tRPAR 
      {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("SUP",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         $$=addr_next_to_last;
         print_asm_table();
      }
   | tLPAR Expression tEQ Expression tRPAR 
      {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("EQU",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         $$=addr_next_to_last;
         print_asm_table();
      }
   | Expression tLT Expression 
      {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("INF",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         $$=addr_next_to_last;
         print_asm_table();
      }
   | Expression tGT Expression 
      {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("SUP",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         $$=addr_next_to_last;
         print_asm_table();
      }
   | Expression tEQ Expression 
      {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("EQU",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         $$=addr_next_to_last;
         print_asm_table();
      }
   | Expression
   {
      $$=get_last_index_ts(table);
   }
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
   tID tASSIGN tNB  
   {
      int index = add_symbol(table,$1,scope);
      add_asm("AFC",2,index,$3);
      print_table(table);
   }
   
   |tID tASSIGN tNB tCOMMA Declaration_const  
   {
      int index = add_symbol(table,$1,scope);
      add_asm("AFC",index,$3);
      print_table(table);
   }
   ;     
   
Declaration_int:
   tID   
   {
      add_symbol(table,$1,scope);
      print_table(table);
   }
   
   | tID tASSIGN Expression 
   {
      remove_last_temp_var(table);
      int addr = add_symbol(table,$1,scope);
      print_table(table);
   }

   | tID tASSIGN Expression tCOMMA Declaration_int 
   {
      int addr = add_symbol(table,$1,scope);
      print_table(table);
   }

   | tID tCOMMA Declaration_int 
   {
      add_symbol(table,$1,scope);
      print_table(table);
   };   


Selection_statement:
   tIF tLPAR Conditions 
   {
      $1 = add_asm("JMF",2,$3,0);
      remove_last_temp_var(table);

   } tRPAR tLBRACE {scope++; } Corps 
   { 
      modif_asm_inst($1,"JMF",2,$3,get_last_index()+1);
      remove_symbols_by_scope(table,scope);                                                                                             
      print_table(table);

   } tRBRACE Else_statement {add_asm("NOP",0);};
   
Else_statement:
   /*empty*/
   |tELSE 
   {
      $1 = add_asm("JMP",1,0);
   } tLBRACE{scope++;} Statement_list tRBRACE
   {
      modif_asm_inst($1,"JMP",1,get_last_index());
      remove_symbols_by_scope(table,scope);
      print_table(table);
   };
         
   
Iteration_statement:
   tWHILE tLPAR 
   {
      $1.index_condition = get_last_index();
   }Conditions
   {
      $1.index_exit = add_asm("JMF",2,$4,0);
      remove_last_temp_var(table);
   } tRPAR tLBRACE{scope++;} Statement_list 
   {
      modif_asm_inst($1.index_exit,"JMF",2,$4,get_last_index()+1);
      add_asm("JMP",1,$1.index_condition);} tRBRACE{
      remove_symbols_by_scope(table,scope);
      print_table(table);
   
   };
   
   
Return_statement: 
   /*empty*/
   | tRETURN Expression tSEMI
   | tRETURN tSEMI;
   
   
Print_statement:
   tPRINT tLPAR Expression tRPAR tSEMI 
   {
      add_asm("PRI",1,$3);
      remove_last_temp_var(table);
   };
   
   
Assignement_statement:
    tID tASSIGN Expression tSEMI  
    {
      int addr = get_adress(table,$1);
      int addr_last= get_last_index_ts(table);
      add_asm("COP",2,addr,addr_last);
      remove_last_temp_var(table);
      print_table(table);
   };


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
