#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Symbol_table.h"



// On initialise une table
/*symbol_table *init_symbol_table() {
    symbol_table *table = (symbol_table*) malloc(sizeof(symbol_table));
    table->first_entry = NULL;
    table->last_entry = NULL;
    return table;
}*/

// ajouter une entree a la table 
void add_symbol(symbol_table *table, char *name, int address) {
    // on verifie s'il existe deja 
    symbol_table_entry *entry = table->first_entry;
    while (entry != NULL) {
        if (strcmp(entry->name, name) == 0) {
            fprintf(stderr, "Symbol %s already defined\n", name);
            exit(1);
        }
        entry = entry->next;
    }

    // on creer une nouvelle entrée 
    entry = (symbol_table_entry*) malloc(sizeof(symbol_table_entry));
    entry->name = strdup(name);
    entry->address = address;
    entry->next = NULL;

    // on ajoute l'entrée
    if (table->first_entry == NULL) {
        table->first_entry = entry;
        table->last_entry = entry;
    } else {
        table->last_entry->next = entry;
        table->last_entry = entry;
    }
}

// On regarde si le symbole est present et on renvoie son adresse 
int get_adress(symbol_table *table, char *name) {
    symbol_table_entry *entry = table->first_entry;
    while (entry != NULL) {
        if (strcmp(entry->name, name) == 0) {
            return entry->address;
        }
        entry = entry->next;
    }
    fprintf(stderr, "Symbol %s not defined\n", name);
    exit(1);
}

// libere la memoire utilisée par la table 
void free_table(symbol_table *table) {
    symbol_table_entry *entry = table->first_entry;
    while (entry != NULL) {
        symbol_table_entry *next = entry->next;
        free(entry->name);
        free(entry);
        entry = next;
    }
    free(table);
}

// affiche la table 
void print_table(symbol_table *table) {
    printf("Symbol table:\n");
    symbol_table_entry *entry = table->first_entry;
    while (entry != NULL) {
        printf("%s\t%d\n", entry->name, entry->address);
        entry = entry->next;
    }
}

// main pour tester les fonctions valide
int main() {
    symbol_table *table = init_symbol_table();
    // Add some symbols to the table
    add_symbol(table, "x", 0);
    add_symbol(table, "y", 1);
    add_symbol(table, "z", 2);
    
    // Look up some symbols in the table
    printf("Address of x: %d\n", get_adress(table, "x"));
    printf("Address of y: %d\n", get_adress(table, "y"));
    printf("Address of z: %d\n", get_adress(table, "z"));
    
    // Print the contents of the symbol table
    print_table(table);
    
    // Free the memory used by the symbol table
    free_table(table);
}
