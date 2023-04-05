
#include <stdio.h>
#include <stdlib.h>

// Ouvre le fichier de sortie en mode écriture
FILE* output_file;
void open_output_file(char* filename) {
   output_file = fopen(filename, "w");
   if (!output_file) {
      fprintf(stderr, "Erreur : impossible d'ouvrir le fichier de sortie '%s'\n", filename);
      exit(1);
   }
}

// Ferme le fichier de sortie
void close_output_file() {
   fclose(output_file);
}

// Fonction pour écrire une instruction ASM
void add_asmvar(char* op, char* param1, int param2, int param3) {
   fprintf(output_file, "%s %s, %d, %d\n", op, param1, param2, param3);
}

void add_asmnb(char* op, int param1, int param2, int param3) {
   fprintf(output_file, "%s %d, %d, %d\n", op, param1, param2, param3);
}
