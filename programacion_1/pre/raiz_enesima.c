#include <stdio.h>


double raiz(double x){
double r = x, t = 0;
while (t != r){
t = r;
r = (x/r + r)/2;
}
return r;
}

   main(){
     double r, x;

      printf("introduzca un numero: ");
      scanf("%i"&x);

   r=raiz(x);

             printf("la raiz de %i es: %i",x,r);
}

