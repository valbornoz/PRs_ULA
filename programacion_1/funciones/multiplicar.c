#include "stdio.h"

    int mult(int a, int b){
        int r;
               r=a*b;
           return r;
      }




   void main(){
         int r,a,b;
           
            printf("introduzca el primer numero: ");
            scanf("%i",&a);
            printf("introduzca el segundo numero: ");
            scanf("%i",&b);

    r=mult(a,b);
 
        printf("el resultado es: %i\n",r);
}

    
