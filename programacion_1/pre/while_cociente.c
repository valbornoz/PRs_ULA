#include <stdio.h>

main()
{
 int a,b,cociente,resto=1;

 printf("Introduzca dos numeros enteros separados por comas.\n");
 scanf("%d,%d",&a,&b);
 if (a<b) {cociente=a; a=b; b=cociente;}
 while (resto>0) {
	cociente=a/b;
	resto=a%b;
	printf("%d = %dx%d + %d\n",a,b,cociente,resto);
	a=b;
	b=resto;
 }
 printf ("El m.c.d es %d\n",a);
 return 0;
}

