#include "stdio.h"

main(){
    int a,f=1,i=1;

    printf("introdusca el numero: ");
    scanf("%i",&a)

    while(i<=a){
    f=f*i;
    i=i++;
   }
      printf("el factorial del numero es: %i\n",a,f);
}
