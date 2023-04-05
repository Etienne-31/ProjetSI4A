#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void construct_asm_file(char *name,int arg1,int arg2, int arg3){
        FILE* fichier = NULL;
        fichier = fopen("asm.txt", "r+");

        if((strcmp(*name, "add") == 0)){
            sptrintf("add %d , %d , %d \n",arg1,arg2,arg3);
        }
        else if((strcmp(*name, "subb") == 0)){
            sptrintf("add %d , %d , %d \n",arg1,arg2,arg3);
        }
        else if((strcmp(*name, "pop") == 0)){
            sptrintf("pop %d\n",arg1);
        }
        else if((strcmp(*name, "ass") == 0)){
            sptrintf("add %d , %d  \n",arg1,arg2);
        }
        else if((strcmp(*name, "memcopy") == 0)){
            sptrintf("add %d , %d  \n",arg1,arg2);
        }

        fclose(fichier);
}