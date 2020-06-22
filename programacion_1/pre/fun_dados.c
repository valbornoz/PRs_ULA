#include "stdio.h"
#include "stdlib.h"
#include "string.h"

float mediana(int r[]);
int moda(int mod, int f[]);

main(){
	int dado1, dado2, r[100], i, f[11]={0,0,0,0,0,0,0,0,0,0,0}, mod, max, n, j;
	float med=0;

srand(time(NULL));

	for(i=0;i<100;i++){
		dado1=rand()%6+1;
		dado2=rand()%6+1;

		r[i]=dado1+dado2;
		f[r[i]-2]=f[r[i]-2]+1;
	}

	med=mediana(r);

	max=f[0];
	for(i=1;i<11;i++){
		if(max<f[i])
		max=f[i];
	}
	
	printf("se han lanzado 2 dados 100 veces\n\n");
	printf("histograma de los resultados obtenidos:\n");

	for(i=0;i<11;i++){
		printf("%i => %i ",i+2,f[i]);
			n=f[i];		
		for(j=0;j<n;j++){
			printf("*");
		}
	printf("\n");
	}	printf("\n");

	printf("la mediana de la suma de sus resultados es %f\n",med);
	
	mod=moda(max,f);

	printf("la moda obtenida es %i\n",mod+2);
}

int moda(int max, int f[]){
	int i;	

	for(i=1;i<11;i++){
		if(max==f[i])
		return i;
	}

}

float mediana(int r[]){

	float med=0;
	int i;

		for(i=0;i<100;i++){
			med=med+r[i];
		}med=med/100;

	return med;
}
