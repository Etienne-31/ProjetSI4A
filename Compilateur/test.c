

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
int compute(int a){
  a=a+1;
  return a;

}
int comp(int a, int b){
  int c=2;
  if (a==b){
    if (a<5){
      a= compute(a);//6
    }
  }else {
    a = compute(b);//8
  }
  return a;
}

int main(){
  int y,x,z;
  y = comp(4,11);//52
  x = comp(4,4);
  z = comp(10,10);
  printf("x est : %d\n",x);//5
  printf("y est : %d\n",y);
  printf("z est : %d\n",z);

}