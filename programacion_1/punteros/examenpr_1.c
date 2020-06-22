#include <stdio.h>
#include <stdlib.h>

int main(){

	int* x = (int*)malloc(sizeof(int));
	int* y = (int*)malloc(sizeof(int));
	int* aux = (int*)malloc(sizeof(int));

	printf("introduzca los numeros a intercambiar\n");
	scanf("%d", x);
	scanf("%d", y);

	aux=x;
	x=y;
	y=aux;


	printf("los valores obtenidos son %d y %d \n", *y, *x);



free(aux);
free(x);
free(y);
	return 0;
}
