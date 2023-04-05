#include <stdio.h>
#include <stdlib.h>

#ifndef Asm_gestion
#define Asm_gestion

// Fonction pour ouvrir le fichier de sortie
void open_output_file(char* filename);

// Fonction pour fermer le fichier de sortie
void close_output_file();

// Fonction pour ajouter une instruction ASM au fichier de sortie
void add_asmvar(char* op,char* param1, int param2, int param3);
void add_asmnb(char* op,int param1, int param2, int param3);

#endif