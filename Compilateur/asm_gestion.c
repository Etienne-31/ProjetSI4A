
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "asm_gestion.h"


instruct_asm asm_table[256];
int next_index = 0;

FILE* output_file;
// Ouvre le fichier de sortie en mode écriture
void open_output_file(char* filename) {
   output_file = fopen(filename, "w");
   if (!output_file) {
      fprintf(stderr, "Erreur : impossible d'ouvrir le fichier de sortie '%s'\n", filename);
      exit(1);
   }
   for (int i = 0; i < next_index; i++) {
        instruct_asm* ins = &asm_table[i];
        fprintf(output_file, "%s ", ins->operation);
        next_operande* current = ins->operandes;
        for (int j = 0; j < ins->nb_operandes; j++) {
            fprintf(output_file, "%d ", current->operande);
            current = current->next;
        }
        fprintf(output_file, "\n");
    }
}

// Ferme le fichier de sortie
void close_output_file() {
   fclose(output_file);
}

void init_asm_table() {
    for (int i = 0; i < 256; i++) {
        strcpy(asm_table[i].operation, "");
        asm_table[i].nb_operandes = 0;
        next_operande *current = asm_table[i].operandes;
        while (current != NULL) {
            next_operande* next = current->next;
            free(current);
            current = next;
        }
        asm_table[i].operandes = NULL;
    }
    next_index = 0;
}

void add_operande(instruct_asm *asminstruct, int operande) {
    next_operande *new_operande = (next_operande *)malloc(sizeof(next_operande));
    new_operande->operande = operande;
    new_operande->next = NULL;
    if (asminstruct->operandes == NULL) {
        asminstruct->operandes = new_operande;
        return;
    }
    next_operande *list_operandes = asminstruct->operandes;
    while (list_operandes->next != NULL)
        list_operandes = list_operandes->next;
    list_operandes->next = new_operande;
}

int add_asm(char* operation, int nb_operandes, ...) {
    instruct_asm* new_ins = (instruct_asm *)malloc(sizeof(instruct_asm));
    strcpy(new_ins->operation, operation);
    new_ins->nb_operandes = nb_operandes;
    new_ins->operandes = NULL;

    va_list valist;
    va_start(valist, nb_operandes);
    for (int i = 0; i < nb_operandes; i++) {
        add_operande(new_ins, va_arg(valist, int));
    }
    va_end(valist);

    if (next_index >= 256) {
        fprintf(stderr, "Plus d'espace dans le tableau d'instructions ASM!\n");
        return -1;
    }
    asm_table[next_index] = *new_ins;
    next_index++;

    return next_index-1; // retourne l'indice de l'instruction ajoutée
}

/*void modif_asm_inst(int index, char* operation, int nb_operandes, ...) {
    instruct_asm* ins = &asm_table[index];
    strcpy(ins->operation, operation);
    ins->nb_operandes = nb_operandes;

    // libérer la mémoire des opérandes précédentes
    next_operande* current = ins->operandes;
    while (current != NULL) {
        next_operande* next = current->next;
        free(current);
        current = next;
    }

    va_list valist;
    va_start(valist, nb_operandes);
    for (int i = 0; i < nb_operandes; i++) {
        add_operande(ins, va_arg(valist, int));
    }
    va_end(valist);
}*/

void modif_asm_inst(int index, char* operation, int nb_operandes, ...) {
    instruct_asm* ins = &asm_table[index];
    strcpy(ins->operation, operation);
    ins->nb_operandes = nb_operandes;

    // libérer la mémoire des opérandes précédentes
    next_operande* current = ins->operandes;
    while (current != NULL) {
        next_operande* next = current->next;
        free(current);
        current = next;
    }

    va_list valist;
    va_start(valist, nb_operandes);
    next_operande* new_head = NULL;
    next_operande* tail = NULL;
    for (int i = 0; i < nb_operandes; i++) {
        int operande = va_arg(valist, int);
        printf("Nouvelle valeur de l'opérande %d: %d\n", i+1, operande);
        next_operande* new_op = malloc(sizeof(next_operande));
        new_op->operande = operande;
        new_op->next = NULL;
        if (new_head == NULL) {
            // Nouvel opérande devient la tête de la liste
            new_head = new_op;
            tail = new_op;
        } else {
            // Ajouter le nouvel opérande à la fin de la liste
            tail->next = new_op;
            tail = new_op;
        }
        printf("Valeur de l'opérande ajouté: %d\n", new_op->operande);
        printf("Pointeur de l'opérande ajouté: %p\n", (void*)new_op);
    }
    ins->operandes = new_head;
    printf("fin de la modif \n");
    va_end(valist);
}



void print_asm_table() {
    printf("Table des instructions ASM:\n");
    for (int i = 0; i < next_index; i++) {
        instruct_asm* ins = &asm_table[i];
        printf("%d: %s ", i, ins->operation);
        next_operande* current = ins->operandes;
        for (int j = 0; j < ins->nb_operandes; j++) {
            if (current != NULL) {
                printf("%d ", current->operande);
                current = current->next;
            }
        }
        printf("\n");
    }
}


void write_asm_file(FILE* output_file) {
    for (int i = 0; i < next_index; i++) {
        instruct_asm* ins = &asm_table[i];
        fprintf(output_file, "%s ", ins->operation);
        next_operande* current = ins->operandes;
        for (int j = 0; j < ins->nb_operandes; j++) {
            fprintf(output_file, "%d ", current->operande);
            current = current->next;
        }
        fprintf(output_file, "\n");
    }
}
int get_last_index() {
    return next_index;
}
#if 0
int main() {
   init_asm_table();
    
    int index2 = add_asm("ADD", 3, 1, 2, 3);
    int index1 = add_asm("JMF", 2, 4, 5);
    int index3 = add_asm("PRI", 1, 6);
    int index4 = add_asm("PRI", 1, 6);
    int index7 = add_asm("PRI", 1, 6);
    //print_asm_table();
    //print_asm_table();
   //modif_asm_inst(index2,"ADD",3,78,88,90);
   modif_asm_inst(index2,"ADD",3,10,9,7);
   int addr_last = get_last_index();
   printf("l'index last est : %d\n", addr_last );
  
   //open_output_file("asm28");
   //close_output_file();
    print_asm_table();
   }

#endif
/*
// Fonction pour écrire une instruction ASM
void add_asminstructvar(char* op, char* param1, int param2, int param3) {
   fprintf(output_file, "%s %s, %d, %d\n", op, param1, param2, param3);
}

void add_asminstructnb(char* op, int param1, int param2, int param3) {
   fprintf(output_file, "%s %d, %d, %d\n", op, param1, param2, param3);
}
*/
