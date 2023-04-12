#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#ifndef Asm_gestion
#define Asm_gestion
FILE* output_file;
typedef struct next_operande next_operande;
struct next_operande {
    int operande;
    next_operande* next;
};

typedef struct {
    char operation[256];
    int nb_operandes;
    next_operande* operandes;
} instruct_asm;

// Fonction pour ouvrir le fichier de sortie
void open_output_file(char* filename);

// Fonction pour fermer le fichier de sortie
void close_output_file();

//init la table asm
void init_asm_table();

//Print la table (pour les tests)
void print_asm_table();

//Ecrire sur le fichier 
void write_asm_file(FILE* output_file);

//retourne l'index de l'instruction ajoutée 
int add_asm(char *instruction, int num_operands, ...);

int get_last_index();

//modifie l'instruction situé a l'index passé en argument 
void modif_asm_inst(int index, char *instruction, int num_operands, ...);

//ajoute un operande
void add_operande(instruct_asm *asminstruct, int operande);

// Fonction pour ouvrir le fichier de sortie
void open_output_file(char* filename);

// Fonction pour fermer le fichier de sortie
void close_output_file();
/*
// Fonction pour ajouter une instruction ASM au fichier de sortie
void add_asmvar(char* op,char* param1, int param2, int param3);
void add_asmnb(char* op,int param1, int param2, int param3);
void addOperande(instruct_asm *asminstruct, int operande);
int next_instruct();
int add_asm(char* operation, int nb_arg);*/




#endif