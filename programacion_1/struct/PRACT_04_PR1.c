#include "stdio.h"
#include "string.h"

struct Fecha{
	int dia, mes, anio;
};

struct Persona{

	char nombre[10];
	char apellido[10];
	int ci;
	struct Fecha natalicio;
	int nota[3];
};

int buscar( struct Persona[], struct Persona, int tamanio);

int main(){


	struct Persona p1[10];

	struct Persona pedro;

	int pos, i, j, np;

		printf("¿cuantas personas desea ingresar?\n");
		scanf("%i",&np);

	for(i=0; i<np; i++){
		printf("introduzca la C.I. de la persona numero %i ",i+1);
		scanf("%d",&p1[i].ci);
		printf("introduzca el nombre de la persona numero %i ",i+1);
		scanf("%s",p1[i].nombre);
		printf("introduzca el apellido de la persona numero %i ",i+1);
		scanf("%s",p1[i].apellido);
		printf("introduzca el dia que nacio la persona numero %i ",i+1);
		scanf("%d",&p1[i].natalicio.dia);
		printf("introduzca el mes en que nacio la persona numero %i ",i+1);
		scanf("%d",&p1[i].natalicio.mes);
		printf("introduzca el año en que nacio la persona numero %i ",i+1);
		scanf("%d",&p1[i].natalicio.anio);

		printf("\n");
		
		for(j=0; j<i; j++){
			if(p1[i].ci==p1[j].ci){
				printf("la persona ya fue ingresada, vuelva a introducir\n");
				i--;
			}
		}
	}
	
	printf("introduzca la C.I. de la persona a buscar ");
	scanf("%i",&pedro.ci);

	pos=buscar(p1,pedro,np);

	if(pos!=-1)

	printf("nombre : %s ", p1[pos].nombre);
	printf("%s\n", p1[pos].apellido);
	printf("natalicio : %d/%d/%d/\n",p1[pos].natalicio.dia,p1[pos].natalicio.mes,p1[pos].natalicio.anio);
	
	return 0;


}

int buscar( struct Persona vector[], struct Persona valor, int tamanio){
	int pos;
	int i;
	for(i=0; i<tamanio; i++){
		if(valor.ci == vector[i].ci){
				pos=i;
				return pos;
		}
 	}

return -1;

}


