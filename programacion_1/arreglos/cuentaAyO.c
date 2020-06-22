#include "stdio.h"

 main(){
     char p[20];
     int i=0, n=0, j=0;
 
            printf("introduzca una palabra: ");
            scanf("%s",&p);

        while((i<20)&&(p[i]!='\0')){
             
              if((p[i]=='o')||(p[i]=='O'))
                 n++;
                 if((p[i]=='a')||(p[i]=='A')){
                       j++;
                      }
                             i++;
                          }
                
               printf("la palabra tiene %i letras 'a' y %i letras 'o'\n", j, n);
}
