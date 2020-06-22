#include<stdio.h>

void aumentar(int *a,int b){
	*a= *a + b;
}

int aumentar2(int a,int b){
	a=a+b;	
	return a ;
}
int main(){
	int a=5;
	int b=3;
	printf("%d \n", a);
	a=aumentar2(a,b);
	printf("%d \n", a);
	aumentar(&a,b);
	
	printf("%d \n", a);
	return 0;
}
