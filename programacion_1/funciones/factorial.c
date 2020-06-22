#include "stdio.h"

 int fat(int x){
     int i=1, r=1;
        while(i<=x){
         r=r*i;
         i++;
        }
           return r;
    }


 void main(){
      int a,r;

            printf("introduzca un numero: ");
            scanf("%i",&a);

       r=fat(a);

           printf("el factorial de %i es: %i\n",a,r);
}
