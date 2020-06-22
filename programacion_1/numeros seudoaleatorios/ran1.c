#include "stdio.h"
#include "stdlib.h"

main(){
	int x, i;
	float sum=0.0;

	srand(time(NULL));

	for(i=0;i<=30;i++){	
		x=rand()%21;
	sum=sum+x;
	}

	printf("el promedio es %f\n",sum/30);
}
