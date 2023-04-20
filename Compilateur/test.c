

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
int compute(int a){
  int c =2;
  a= a+c+2;//30
  return a;
}
int comp(int a, int b){
  int c=2;
  if (a+c==b+c){
    if (a<5){
      a= compute(a);
    }
  }else {
    a = compute(b);
    printf("b a comp : %d\n",b);
    printf("a a comp : %d\n",a);
  }
  return a;
}



int compute2(int a){
  int c = 10;
  int d,f;
  c=compute(a);//26
  d=comp(2,2);
  printf("d a compute2 : %d\n",d);
  f=comp(3,4);
  printf("f a compute2 : %d\n",f);
  a=a+c;//52
  return a;
}
int main(){
  int x,y,z,b,e;
  y = compute2(10);//52
  x = compute(20);//3
  printf("y : %d\n",y);//28
  printf("x : %d\n",x);
}