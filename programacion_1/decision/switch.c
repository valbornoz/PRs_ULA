#include "stdio.h"

main(){
	int n;

	printf("introduzca su nota: ");
	scanf("%i",&n);

	switch(n){

	case 0: case 1: case 2: case 3: case 4: case 5:
	printf("su calificasion es pesima!\n");
	break;

	case 6: case 7: case 8: case 9:
	printf("su calificasion es mala!\n");
	break;

	case 10: case 11: case 12: case 13:
	printf("su calificasion es regular!\n");
	break;

	case 14: case 15: case 16: case 17:
	printf("su calificasion es buena!\n");
	break;	

	case 18: case 19: case 20:
	printf("su calificasion es exelente!\n");
	break;

	default:
	printf("ERROR:\ncalificasion invalida vuelba a ejecutar\n");
	}
}
