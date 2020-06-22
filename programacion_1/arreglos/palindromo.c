#include "stdio.h"

 main(){
      char p[20];
      int i=0, n=0;
              printf("introduzca la palabra: ");
              scanf("%s",p);

      while((n<20)&&(p[n]!='\0')){
       n=n+1;
       }
          i=n-1;
   printf("%s al revés, se escribe: ",p);
   while(i>=0) {
   	printf("%c",p[i]);       
      i=i-1;
   }
   printf("\n");

            

}
