#include "stdio.h"

 main(){
     int n, i, max, min, v[20];
     float pro;
     
          printf("¿cuantos numeros va a introducir?\n");
          scanf("%i",&n);

          for(i=0;i<n;i++){
           printf("introduzca un numero: ");
          scanf("%i",&v[i]);
         }
           max = min = pro = v[0];
                 for(i=1;i<n;i++){
                    if(max<v[i])
                      max=v[i];
                       if(min>v[i])
                            min=v[i];  
                  }
                     for(i=1;i<n;i++){
                       pro=pro+v[i];}

         printf("maximo: %i\nminimo: %i\npromedio: %.2f\n",max,min,pro/n);          
          
}
     
