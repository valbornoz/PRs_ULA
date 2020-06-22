#include "stdio.h"
main(){
int x;
x=10;
int *px;
px=&x;
printf("%i\n",x);
printf("%i\n",px);
printf("%i\n",*px);
*px=8;
printf("%i\n",x);
}
