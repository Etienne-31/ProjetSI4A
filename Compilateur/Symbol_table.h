
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifndef Symbol_table
#define Symbol_table

// Define a structure for the symbol table
typedef struct symbol_table_entry {
char *name;
int address;
int scope;
struct symbol_table_entry *next;
} symbol_table_entry;

// Define a structure for the symbol table
typedef struct symbol_table {
symbol_table_entry *first_entry;
symbol_table_entry *last_entry;
} symbol_table;

// On initialise une table
symbol_table *init_symbol_table();

// ajouter une entree a la table 
int add_symbol(symbol_table *table, char *name, int scope);

int add_temp_var(symbol_table *table);

// On regarde si le symbole est present et on renvoie son adresse 
int get_adress(symbol_table *table, char *name);

// libere la memoire utilisée par la table 
void free_table(symbol_table *table);

//affiche la table
void print_table(symbol_table *table);

// libere la variable temporaire 
void remove_last_temp_var(symbol_table *table);

int get_last_index_ts(symbol_table *table);

//enleve les symboles de chaque scope
void remove_symbols_by_scope(symbol_table *table, int scope);

#endif