#include "stdio.h"
#include "stdlib.h"

main(){
	float x;
	int i;
	
	srand(time(NULL));

	for(i=0;i<=20;i++){
	x=rand()/(float)(RAND_MAX);
	printf("%f\n",x);
	}
}
