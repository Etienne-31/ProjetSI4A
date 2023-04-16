#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure représentant une ligne dans la table de fonctions
typedef struct {
    char *name;
    int asm_address;
    int params_count;
} function_line;

void init_function_table();

void add_function(char *name, int asm_address,int params_count);

void print_function_table();

int get_function_params(char *name);

int find_function_asm_address(char *name);