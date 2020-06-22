#include "stdio.h"

  char cont(char p[]){
       int j=0;

         while((j<20)&&(p[j]!='\0')){
                  j++;
       } return j;
 }
    int palindromo(char p[]){
                 int i=0,j;
              
               while((i!='\0')&&(j!=0)){
                   i++; j--;

              if(p[i]==p[j]){
                return 1;
             }else
                  return 0;
            }
      }

 void main(){
     char p[20];
     int i=0, j;

             printf("introduzca una palabra: \n");
             scanf("%s",p);

        j=cont(p);
         palindromo(p);

                          if(j)
                            printf("la palabra %s es un palindromo\n",p);
                          else
                            printf("la palabra %s no es un palindromo\n",p);
}
                              
