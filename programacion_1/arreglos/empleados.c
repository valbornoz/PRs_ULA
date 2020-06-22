#include "stdio.h"

 main(){
   int m=0, n=0, i=0, h, ed[20], hj[20];

               printf("cuantos empleados posee la empresa: ");
               scanf("%i",&h);

            for(i=0;i<h;i++){
                 printf("introduzca la edad del empleado %i: ",i+1);
                 scanf("%i",&ed[i]);
                 printf("cuantos hijos tiene el empleado %i: ",i+1);
                 scanf("%i",&hj[i]);
             
             
                 if((ed[i]>40)&&(hj[i]<1))
                      m++;          
                 if((ed[i]<25)&&(hj[i]>2))
                      n++;       }

         printf("en la empresa existen %i empleados con mas de 40 años que no poseen hijos\n", m);
         printf("en la empresa existen %i empleados con almenos 25 años que poseen mas de 2 hijos\n", n);
}
