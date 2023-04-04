#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

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

//symbol_table *init_symbol_table();
void add_symbol(symbol_table *table, char *name, int address);
int get_adress(symbol_table *table, char *name);
void free_table(symbol_table *table);
void print_table(symbol_table *table);
