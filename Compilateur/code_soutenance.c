// while imbriqués
int main(){
    int b=4;
    int a =3;
    while (b<9){
        b=b+1;
        while(a<8){
        a=a+1;
        }
    }
    print(a);//8
    print(b);//9
}

// appel de fonction avec if imbriqué dans l'appel de fonction

int compute(int a){
  a=a+1;
  return a;

}
int comp(int a, int b){
  int c=2;
  if (a==b){
    if (a<5){
      a= compute(a);
    }
  }else {
    a = compute(b);
  }
  return a;
}

int main(){
  int y,x,z;
  y = comp(4,11);
  x = comp(4,4);
  z = comp(10,10);
  print(x);
  print(y);
  print(z);

}