#include "stdio.h"

main(){
	int a, b, c,*pa,*pb;

	printf("introduzca el numero a: ");
	scanf("%i",&a);
	printf("introduzca el numero b: ");
	scanf("%i",&b);

pa=&a;
pb=&b;

c=a;


*pa=*pb;
*pb=c;

	printf("el numero a es: %i\n",a);
	printf("el numero b es: %i\n",b);
}
