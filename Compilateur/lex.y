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
int addr_ret;
int queue[100];
int nbparam_decl;
int index_queue = 0;
int addr_main;
int addr_func;
int nbparam_call;
int decalage;
int index_jmp_main;
%}

%union { int nb; char* var; struct {int index_condition; int index_exit;}index_while;}
%token tINT tVOID tCONST tMAIN tRETURN tPRINT
%token tADD tSUB tMUL tDIV tLT tGT tNE tEQ tGE tLE tASSIGN tAND tOR tNOT
%token tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA
%token <nb> tNB
%token <nb> tIF
%token <nb> tLPAR
%token <nb> tELSE
%token <index_while> tWHILE
%token <var> tID
%left tADD tSUB tMUL tDIV tEQ tNE
%nonassoc tLT tGT tLE tGE
%type <nb> Expression
%type <nb> Else_statement
%type <nb> Conditions
%type <nb> Condition
%type <nb> Declaration_int
%type <nb> Facteur
%start Program

%%
Program: {
   index_jmp_main = add_asm("JMP",1,0);
}Function_list;


Function_list:
   Function 
   | Function_list Function;
   
   
Function:
    Type_specifier tMAIN 
    {
      addr_main = get_last_index();
      modif_asm_inst(index_jmp_main,"JMP",1,addr_main);

      /*addr_main = get_last_index();
      for(int i; i>=0;i--){
         modif_asm_inst(queue[index_queue],"JMP",1,addr_main);
         index_queue--;
      }*/
    }
    tLPAR Parameter_list tRPAR  tLBRACE Corps Return_statement tRBRACE 
    {
      print_table(table);
      print_asm_table();
      free_table(table);
      scope=0;
   }

   | Type_specifier tID tLPAR Parameter_list tRPAR 
   {  
      /*queue[index_queue] =add_asm("JMP",1,addr_main);
      add_function($2,queue[index_queue],nbparam_decl);
      index_queue++;*/
      add_function($2, get_last_index(),nbparam_decl);
      decalage = get_last_index_ts(table);
      addr_ret = add_return_address(table,nbparam_decl);

   }tLBRACE Corps Return_statement tRBRACE 
   {  
      nbparam_decl=0;
      print_table(table);
      free_table(table);
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
   {
      add_symbol(table,$2,scope);
      nbparam_decl++;
   }
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
   tID tLPAR Arguments tRPAR
   {
      int addrfunc = find_function_asm_address($1);
      //add_asm("JMP",1,addrfunc);
      nbparam_call = get_function_params($1);
      
      add_asm("CALL",2,addrfunc,get_last_index_ts(table)-nbparam_call);
      //remove_last_temp_var(table);
      

   };

Arguments:
   /*empty*/
   | Expression 
   | Expression tCOMMA Arguments


Expression:
        Expression tADD Expression 
        { 

         int addr_last= get_last_index_ts(table);
         int addr_next_to_last = get_last_index_ts(table)-1;
         add_asm("ADD",3,addr_next_to_last,addr_next_to_last,addr_last);
         remove_last_temp_var(table);
         
         
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
              // affecter tnb a l'adresse de la variable temp 
              add_asm("AFC",2,addrtemp,$1);
            }
        |tID {int addr = get_adress(table,$1);
             int addrtemp = add_temp_var(table);
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
         
      }
   | tLPAR Expression tGT Expression tRPAR 
      {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("SUP",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         $$=addr_next_to_last;
         
      }
   | tLPAR Expression tEQ Expression tRPAR 
      {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("EQU",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         $$=addr_next_to_last;
      }
   | Expression tLT Expression 
      {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("INF",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         $$=addr_next_to_last;
      }
   | Expression tGT Expression 
      {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("SUP",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         $$=addr_next_to_last;
      }
   | Expression tEQ Expression 
      {    
         int addr_next_to_last = get_last_index_ts(table)-1;
         int addr = get_last_index_ts(table);
         add_asm("EQU",3,addr_next_to_last,addr_next_to_last,addr);
         remove_last_temp_var(table);
         $$=addr_next_to_last;
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
   }
   
   |tID tASSIGN tNB tCOMMA Declaration_const  
   {
      int index = add_symbol(table,$1,scope);
      add_asm("AFC",index,$3);
   }
   ;     
   
Declaration_int:
   tID   
   {
      add_symbol(table,$1,scope);
   }
   
   | tID tASSIGN Expression 
   {
      remove_last_temp_var(table);
      int addr = add_symbol(table,$1,scope);
   }

   | tID tASSIGN Expression
   {
      remove_last_temp_var(table);
      int addr = add_symbol(table,$1,scope);
   }
    tCOMMA Declaration_int 
   

   | tID tCOMMA Declaration_int 
   {
      add_symbol(table,$1,scope);
   };   


Selection_statement:
   tIF tLPAR Conditions 
   {
      $1 = add_asm("JMF",2,$3,0);
      remove_last_temp_var(table);

   }tRPAR tLBRACE {scope++;} Corps  tRBRACE
   { 
      modif_asm_inst($1,"JMF",2,$3,get_last_index());
      remove_symbols_by_scope(table,scope);
      scope--; 
      $2 = get_last_index();


   } Else_statement{if ($11 == 1) { 
         modif_asm_inst($1,"JMF",2,$3,$2+1);
      }else {
         modif_asm_inst($1,"JMF",2,$3,$2);
      }};
  
Else_statement:
   tELSE 
   {
      $1 = add_asm("JMP",1,0);
   } tLBRACE{scope++;} Statement_list tRBRACE
   {
      modif_asm_inst($1,"JMP",1,get_last_index());
      remove_symbols_by_scope(table,scope);
      scope--;
      $$=1;
   }
   |{$$=0;};
         
   
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
      add_asm("JMP",1,$1.index_condition);
      modif_asm_inst($1.index_exit,"JMF",2,$4,get_last_index());
      } tRBRACE
   {
      remove_symbols_by_scope(table,scope);
      scope--;
   
   };
   
   
Return_statement: 
   /*empty*/
   | tRETURN Expression tSEMI
   {
      add_asm("BX",2,addr_ret,$2);
      remove_last_temp_var(table);
   }
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
   }
   |tID tASSIGN Function_call tSEMI
   {
      add_temp_var(table);
      int addr = get_adress(table,$1);
      int result = get_last_index_ts(table);
      int first_param = get_last_index_ts(table)- nbparam_call;
      add_asm("COP",2,first_param,result);
      remove_last_temp_var(table);
      add_asm("COP",2,addr,first_param);
      for(int i=0; i<nbparam_call;i++){remove_last_temp_var(table);}
      nbparam_call = 0;
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
