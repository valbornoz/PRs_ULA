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

int buscar( struct Persona[], struct Persona);

int main(){


	struct Persona p1[10];

	struct Persona pedro;

	int pos;
	int i;

	for(int i=0; i<10; i++){
		scanf("%d",&p1[i].ci);
		scanf("%s",p1[i].nombre);
		scanf("%s",p1[i].apellido);
		scanf("%d",&p1[i].natalicio.dia);
		scanf("%d",&p1[i].natalicio.mes);
		scanf("%d",&p1[i].natalicio.año);

	}

	pedro.ci=33;

	pos=buscar(p1,pedro,10);

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


