#include "stdio.h"

int main(){
    int a,b,i=0,r=1;

    printf("introdusca la base: ");
    scanf("%i",&a);
    printf("introdusca el exponente: ");
    scanf("%i",&b);

  while(i<b){
  r=r*a;
  i=i++;
  }
  printf("el resultado es: %i^%i=%i\n",a,b,r);
}
