#include "iostream"

using namespace std;

void f(char*, int*, float*);

main(){

	char nombre[20];
	int ci;
	float sueldo;


	f(nombre,&ci,&sueldo);

	cout<<nombre<<" "<<ci<<" "<<sueldo<<" "<<endl;


}

void f(char *n, int *c, float *s){

	cout<<"NOMBRE: "<<endl;
	cin>>n;
	cout<<"CEDULA: "<<endl;
	cin>>*c;
	cout<<"SUELDO: "<<endl;
	cin>>*s;
}
