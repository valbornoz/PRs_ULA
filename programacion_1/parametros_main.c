#include "stdio.h"

int main(int argv,char **argvc){

	printf("%s\n",argvc[0])

	if(argv>1)
		if(strcmp(argv[1],"hola")==0)
			printf("chao");
	printf("\n");
	return 0;


}
