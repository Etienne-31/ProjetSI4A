

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
int main(){
    int b=4;
    int a =3;
    while (b<9){
        b=b+1;
        while(a<8){
        a=a+1;
        }
    }
    printf("a : %d\n",a);
    printf("b : %d\n",b);
}