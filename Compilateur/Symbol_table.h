
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
void add_symbol(symbol_table *table, char *name, int address);

// On regarde si le symbole est present et on renvoie son adresse 
int get_adress(symbol_table *table, char *name);

// libere la memoire utilisée par la table 
void free_table(symbol_table *table);

//affiche la table
void print_table(symbol_table *table);
#endif