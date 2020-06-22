#include "stdio.h"

 main(){
     char p[20];
     int i=0;
 
            printf("introduzca una palabra: ");
            scanf("%s",&p);

        while((i<20)&&(p[i]!='\0')){
              i++;
           }
                
               printf("la palabra tiene %i letras\n",i);
}
