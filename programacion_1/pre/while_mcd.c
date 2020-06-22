#include "stdio.h"

 main(){
   int a,b,c;

             printf("introduzca el primer numero: ");
             scanf("%i",&a);
             printf("introduzca el segundo numero: ");
             scanf("%i",&b);

            if(a%b!=0)
                 while(b/a%b!=0){
                  c=b/a%b;}
                           
            printf("el mcd es %i \n",c);
}
